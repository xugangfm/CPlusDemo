//
//  main.cpp
//  CPlusDemo
//
//  Created by xugang on 7/20/14.
//  Copyright (c) 2014 RongCloud. All rights reserved.
//

#include <iostream>
#include "Rect.h"
#include "CustomTemplate.h"

using namespace std;
using namespace custom;

// template <class TT>
//
// TT MyMax(TT a,TT b) {
//    if (a<b) {
//        return b;
//    }else
//    {
//        return a;
//    }
//}

class A {
public:
  A() { std::cout << "create A\n"; };
  ~A() { std::cout << "delete A\n"; }
};

class B : public A {
public:
  B() { std::cout << "create B\n"; };
  ~B() { std::cout << "delete B\n"; }
};

void TestName_Space(void) {
  // xx= 190;
  // insert code here...
  std::cout << "Hello, World!\n";

  custom::Rect *frame = new custom::Rect();

  frame->x = xx;
  frame->y = custom::yy;

  frame->printo();
}
void TestTemplate() {

  int ret = MyMax(5, 8);

  printf("max ==>%d\n", ret);

  char a = MyMax('A', 'B');
  printf("max ==>%c\n", a);
}

void TestCQI() {

  Rect *frame = new Rect();

  CQIPtr<Rect, QI_NEW> obj(frame);

  obj->printo();
  // obj.Free();
  // delete obj;
}

int main(int argc, const char *argv[]) {

  // TestName_Space();
  // TestTemplate();

  // myClass<int, int> *obj = new myClass<int, int>(5, 9);

  // myClass<string,string> *obj = new myClass<string,string>("dwefde",
  // "42343");

  // obj->show();

  // A *a =new B();
  // delete a;

  TestCQI();

  return 0;
}
