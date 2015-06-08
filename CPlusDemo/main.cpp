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
#include <memory>
#include <string>
#include <functional>
#include <vector>
#include <set>
#include <mutex>
#include <future>
#include <list>

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
std::unique_ptr<Rect> frame ;

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
unique_ptr<int> Func(unique_ptr<int> a)

{
    
    cout<<(*a)++<<endl;
    
    return a;
    
}
void TestPTR(){
    
    //Rect *frame = new Rect();
    
    frame= std::make_unique<Rect>();
    frame->w = 100;
    frame->printo();
    
    std::unique_ptr<Rect> frame0 = std::move(frame);
    frame0->printo();
    
    frame0.reset();// 显示释放内存
    
    std::shared_ptr<Rect> frame1 = std::make_shared<Rect>();
    
    frame1->x = 10;
    frame1->y = 11;
    
    
    
    //std::shared_ptr<Rect> frame1_1 = std::move(frame1);
    std::shared_ptr<Rect> frame1_1 = frame1;
    frame1_1->printo();
    frame1->printo();
    
    

    //weak_freme.printo();
    
    
    std::cout << "\n====\n" << std::endl;
    
    std::unique_ptr<int> number = std::make_unique<int>(10);
    std::shared_ptr<int> number2(new int(12));
    std::shared_ptr<int> number3(new int(13));
    std::weak_ptr<int> weak_number = number2;
    //std::unique_ptr<int> result = Func(move(number));
    number = Func(move(number));;
    std::cout << *number << std::endl;
    
    std::cout << "\n====\n" << std::endl;
    
    auto _number = Func(move(number));;
    std::cout << *_number << std::endl;
    std::cout << "\n====\n" << std::endl;
    
    
    number3.swap(number2);
    
    std::cout << "number2="<< *number2 << std::endl;
    std::cout << "number3="<< *number3 << std::endl;
    
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

  //TestCQI();
    TestPTR();

  return 0;
}
