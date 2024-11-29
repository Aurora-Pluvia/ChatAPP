#pragma once
#include "const.h"
#include "hiredis.h"
#include <queue>
#include <atomic>
#include <mutex>
#include "Singleton.h"


class RedisConPool {
public:
	RedisConPool(size_t poolSize, const char* host, int port, const char* pwd)
		: poolSize_(poolSize), host_(host), port_(port), b_stop_(false) {
		//连接
		for (size_t i = 0; i < poolSize_; ++i) {
			auto* context = redisConnect(host, port);
			if (context == nullptr || context->err != 0) {
				if (context != nullptr) {
					redisFree(context);
				}
				continue;
			}
			//认证
			auto reply = (redisReply*)redisCommand(context, "AUTH %s", pwd);
			if (reply->type == REDIS_REPLY_ERROR) {
				std::cout << "认证失败" << std::endl;
				//执行成功 释放redisCommand执行后返回的redisReply所占用的内存
				freeReplyObject(reply);
				redisFree(context);
				continue;
			}
			//执行成功 释放redisCommand执行后返回的redisReply所占用的内存
			freeReplyObject(reply);
			std::cout << "认证成功" << std::endl;
			connections_.push(context);
		}
	}
	~RedisConPool() {
		std::lock_guard<std::mutex> lock(mutex_);
		while (!connections_.empty()) {
			connections_.pop();
		}
	}
	redisContext* getConnection() {
		std::unique_lock<std::mutex> lock(mutex_);
		cond_.wait(lock, [this] {
			if (b_stop_) {
				return true;
			}
			return !connections_.empty();
			});
		//如果停止则直接返回空指针
		if (b_stop_) {
			return  nullptr;
		}
		auto* context = connections_.front();
		connections_.pop();
		return context;
	}
	void returnConnection(redisContext* context) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (b_stop_) {
			return;
		}
		connections_.push(context);
		cond_.notify_one();
	}
	void Close() {
		b_stop_ = true;
		cond_.notify_all();//唤醒所有正在挂起等待连接的线程
	}
private:
	std::atomic<bool> b_stop_;
	size_t poolSize_;
	const char* host_;
	int port_;
	std::queue<redisContext*> connections_;
	std::mutex mutex_;
	std::condition_variable cond_;
};


class RedisMgr: public Singleton<RedisMgr>, 
	public std::enable_shared_from_this<RedisMgr>
{
	friend class Singleton<RedisMgr>;
public:
	~RedisMgr();
	//bool Connect(const std::string& host, int port);//在池中已经封装了连接操作
	bool Get(const std::string& key, std::string& value);//获取key对应的value
	bool Set(const std::string& key, const std::string& value);//设置key和value
	bool Auth(const std::string& password);//密码认证
	bool LPush(const std::string& key, const std::string& value);//左侧push
	bool LPop(const std::string& key, std::string& value);//左侧pop
	bool RPush(const std::string& key, const std::string& value);//右侧push
	bool RPop(const std::string& key, std::string& value);//右侧pop
	bool HSet(const std::string& key, const std::string& hkey, const std::string& value);//设置二级key的值
	bool HSet(const char* key, const char* hkey, const char* hvalue, size_t hvaluelen);//处理二进制数据
	std::string HGet(const std::string& key, const std::string& hkey);//获取二级key的值
	bool Del(const std::string& key);//删除操作
	bool ExistsKey(const std::string& key);//判断键值是否存在
	void Close();//关闭


private:
	RedisMgr();
	std::unique_ptr<RedisConPool> _con_pool;
};

