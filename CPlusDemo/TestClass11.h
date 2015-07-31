//
//  TestClass11.h
//  CPlusDemo
//
//  Created by xugang on 15/7/30.
//  Copyright (c) 2015年 RongCloud. All rights reserved.
//

#ifndef __CPlusDemo__TestClass11__
#define __CPlusDemo__TestClass11__
#include <string>
#include <cstdint>
#include <chrono>
#include <vector>
#include <memory>
#include <stdio.h>
#include <iostream>


class Talk {
private:
    int32_t flag = -1;

public:
    Talk(int32_t _flag)
    {
        this->flag = _flag;
        std::cout << " addr: " << this << " constructor called flag :" << flag << std::endl;
    }
    Talk(const Talk& other)
    {
        std::cout << " addr: " << this << " copy constructor called flag :" << flag << std::endl;
        this->flag = other.flag;
    }

    Talk(const Talk&& other)
    {
        std::cout << " addr: " << this << " move constructor called flag :" << flag << std::endl;
        this->flag = other.flag;
    }

    Talk& operator=(Talk other)
    {
        std::cout << " addr: " << this << " operator= called flag :" << flag << std::endl;
        this->flag = other.flag;

        return *this;
    }

    void Print() { std::cout << "PRINT : addr: " << this << "flag :" << flag << std::endl; };
};

Talk __global_int_talk(int flag);

#endif /* defined(__CPlusDemo__TestClass11__) */
