//
//  TestStdContainer.cpp
//  CPlusDemo
//
//  Created by xugang on 15/7/31.
//  Copyright (c) 2015年 RongCloud. All rights reserved.
//

#include "TestStdContainer.h"

void TestVector()
{

    std::vector<std::string> array;

    for (int i = 0; i < 10; i++) {

        char s[64];
        sprintf(s, "%d", i);

        std::string sss(s);

        array.push_back(sss);
    }
    
    array.pop_back();

    for (auto& item : array) {
        std::cout << item ;
        
    }
    std::cout << std::endl;
    std::vector<std::string>::iterator it = array.begin();
    std::vector<std::string>::iterator it_e = array.end();
    
    std::cout << *it << std::endl;
    std::cout << *(it_e-1) << std::endl;
    
    std::cout << array.front()<< std::endl;
    std::cout << array.back()<< std::endl;
    
    
    std::vector<std::string>::reverse_iterator it_r = array.rbegin();
    std::vector<std::string>::reverse_iterator it_e_r = array.rend();
    
    std::cout << *it_r << std::endl;
    std::cout << *(it_e_r-1) << std::endl;
    
    std::vector<std::string>::iterator indexp = array.begin();
    do{
    std::cout << *indexp ;
        indexp++;
    
    }while (indexp != array.end()) ;
    
    
}
void TestMap(){
    
    std::map<std::string, int> set;
    
    for (int i = 0; i < 10; i++) {
        
        char s[64];
        sprintf(s, "%d", i);
        
        std::string sss(s);
        set.insert(std::map<std::string,int>::value_type(s,i));
       
    }
    
    set["n"] = 1000;
    
    auto it = set.find("n");
    
    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
    
    
}
