#ifndef SINGLETON_H
#define SINGLETON_H
#include "global.h"

//单例模式
template <typename T>
class Singleton{
protected://不允许外部访问，但允许子类调用构造
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;//不允许拷贝构造
    Singleton& operator = (const Singleton<T>& st) = delete;//不允许拷贝赋值
    static std::shared_ptr<T> _instance;//静态智能指针，所有Singleton都返回同一个实例
public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;//只有第一次调用该函数时才会初始化
        std::call_once(s_flag, [&](){//只有初始化s_flag时才会执行
            _instance = std::shared_ptr<T>(new T);
        });
        return _instance;
    }

    //打印指针地址
    void PrintAddress(){
        std::cout << _instance.get() << std::endl;
    }

    ~Singleton(){
        std::cout << "this is singleton destruct" << std::endl;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;//静态成员一定要进行初始化

#endif // SINGLETON_H
