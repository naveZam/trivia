#pragma once
#define MAKE_SINGLETON_CLASS(className) \
public: \
    static className& getInstance() \
    { \
        static className instance; \
        return instance; \
    } \
\
    className(const className&) = delete; \
    className& operator=(const className&) = delete; \
\
private: \
    className();\
private: