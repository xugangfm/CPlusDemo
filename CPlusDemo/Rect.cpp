//
//  Rect.cpp
//  CPlusDemo
//
//  Created by xugang on 7/20/14.
//  Copyright (c) 2014 RongCloud. All rights reserved.
//

#include "Rect.h"

//using namespace custom;

namespace custom {
    Rect::Rect(){
        this->x=0;
        this->y=0;
        this->w=0;
        this->h=0;
    }
    Rect::~Rect()
    {
        
    }
    
    void Rect::printo(){
        
        printf("(%d,%d,%d,%d)\n",x,y,w,h);
    }

    
}

int custom::yy = 99;

int xx = 100;