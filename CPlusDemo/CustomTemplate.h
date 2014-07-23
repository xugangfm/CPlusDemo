//
//  CustomTemplate.h
//  CPlusDemo
//
//  Created by xugang on 7/23/14.
//  Copyright (c) 2014 RongCloud. All rights reserved.
//

#ifndef CPlusDemo_CustomTemplate_h
#define CPlusDemo_CustomTemplate_h
#include <iostream>

//模板函数可以看做安全的宏定义，不能吧申明和定义分开
template <class TT>
TT MyMax(TT a,TT b) {
    if (a<b) {
        return b;
    }else
    {
        return a;
    }
}

template <typename TTT>
TTT MyMin(TTT a,TTT b) {
    if (a<b) {
        return a;
    }else
    {
        return b;
    }
}

template<typename T1,typename T2>

class myClass{
    
private:
    
    T1 I;
    
    T2 J;
    
public:
    
    myClass(T1 a, T2 b);//Constructor
    
    void show();
    
};

//这是构造函数

//注意这些格式

template <typename T1,typename T2>

//myClass<T1,T2>::myClass(T1 a,T2 b):I(a),J(b){}

myClass<T1,T2>::myClass(T1 a,T2 b){
    this->I=a;
    this->J=b;
}

//这是void show();

template <typename T1,typename T2>

void myClass<T1,T2>::show()

{
    
    std::cout<<"I="<<I<<", J="<<J<<std::endl;
    
}



#endif
