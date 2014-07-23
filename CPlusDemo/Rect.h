//
//  Rect.h
//  CPlusDemo
//
//  Created by xugang on 7/20/14.
//  Copyright (c) 2014 RongCloud. All rights reserved.
//

#ifndef __CPlusDemo__Rect__
#define __CPlusDemo__Rect__

#include <iostream>


extern int xx;

namespace custom {
    
  extern  int yy;
    
    
    class Rect{
        
    public:
        int x;
        int y;
        int w;
        int h;
    public:
        Rect();
        virtual ~Rect();
        void printo();
    };
}


#endif /* defined(__CPlusDemo__Rect__) */
