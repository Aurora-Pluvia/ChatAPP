#pragma once
#include "Singleton.h"
#include <functional>
#include <map>
#include "const.h"

class HttpConnection;

typedef std::function<void(std::shared_ptr<HttpConnection>)> HttpHandler;//处理器

class LogicSystem : public Singleton<LogicSystem> {
	friend class Singleton<LogicSystem>;
public:
	~LogicSystem();
	bool HandleGet(std::string path, std::shared_ptr<HttpConnection> con);
	bool HandlePost(std::string path, std::shared_ptr<HttpConnection> con);
	void RegGet(std::string url, HttpHandler handler);//注册get请求
	void RegPost(std::string url, HttpHandler handler);//注册post请求
private:
	LogicSystem();
	std::map<std::string, HttpHandler> _post_handlers;//处理post请求的集合
	std::map<std::string, HttpHandler> _get_handlers;//处理get请求的集合
};

