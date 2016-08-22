//
//  main.cpp
//  CppClassLog
//
//  Created by 朱越 on 2016/8/20.
//  Copyright © 2016年 ZhuYue. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

#include <cstdio>

#include "Log.h"
using namespace std;
using zhuyuesut::log;

int main(int argc, const char * argv[]) {
    int a = 2;
    double b = 3;
    char c = '$';
    long d = 5;
    bool e = true;
    log(a, b, c, d, e);
    LOG(a, b, c, d, e);
    return 0;
}
