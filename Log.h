//
//  Log.h
//  CppClassLog
//
//  Created by 朱越 on 2016/8/20.
//  Copyright © 2016年 ZhuYue. All rights reserved.
//

#ifndef Log_h
#define Log_h

#include <iostream>
#include <string>

#define LOG(...) do {\
        log(std::string("Log: " "(" #__VA_ARGS__ "), function ")\
                .append(__FUNCTION__)\
                .append(", file " __FILE__ ", line " STR(__LINE__) ", value(s) "),\
            __VA_ARGS__);\
    } while (false)
#define STR(x) _VAR(x)
#define _VAR(x) #x

namespace zhuyuesut {
    class Log {
    private:
        template <typename T>
        static void print(std::ostream &os, T &&t) {
            os << std::forward<T>(t) << '.' << std::endl;
        }
        template <typename T, typename... Args>
        static void print(std::ostream &os, T &&t, Args&& ...args) {
            os << std::forward<T>(t) << '\t';
            print(os, std::forward<Args>(args)...);
        }
    public:
        template <typename... Args>
        Log& operator() (Args&& ...args){
            print(std::clog, std::forward<Args>(args)...);
            return *this;
        }
    } log;
    extern Log log;
}

#endif /* Log_h */
