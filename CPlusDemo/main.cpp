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
#include "json11.hpp"
#include "Calculate.h"

using namespace std;
using namespace custom;

using namespace json11;

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
    
    //number2.get();
    //weak_number.lock();
    
    std::cout << "weak-number2="<< *(weak_number.lock()) << std::endl;
    
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

void Testjson()
{
    #define FAILED_IF(state) do { if(state) { ; return; } }while(0)
    std::string str = "{\"requestTime\":1433838568,\"responseTime\":1433838568,\"data\":{\"recentTalk\":[{\"version\":\"1.0\",\"timeStamp\":1433838568,\"value\":[{\"msgNewCount\":\"0\",\"msgCount\":\"7\",\"updateTime\":\"1433838552\",\"msgType\":\"post_private\",\"toId\":\"3513216745\",\"toName\":\"\u8bbf\u5ba2216745\",\"lastMsg\":{\"msgId\":90978783245,\"msgSeq\":0,\"senderId\":\"27648860\",\"senderName\":\"william010\",\"contents\":[[\"font\",{\"color\":\"000\",\"name\":\"\u5b8b\u4f53\",\"size\":10,\"style\":[0,0,0]}],\"434\",[\"post\",{\"id\":\"0_0_0_0\",\"title\":\"\"}]]}}]}],\"talkupdatetime\":\"1433405878\"},\"errorCode\":0,\"errorMsg\":\"no error\"}";
    
    std::string error;
    
    auto jsonobject = json11::Json::parse(str, error);;
    FAILED_IF(!error.empty());
    std::cout << jsonobject["requestTime"].int32_value() <<std::endl;
    std::cout << jsonobject["errorMsg"].string_value() <<std::endl;
    
    auto jsonData =jsonobject["data"];
    
    std::cout << jsonData["talkupdatetime"].string_value() <<std::endl;
    
    auto talkAttay = jsonData["recentTalk"];
    
    FAILED_IF(!talkAttay.is_array());
    
    for (auto& talk : talkAttay.array_items()) {
        
        auto item = talk["version"].string_value();
        std::cout << item <<std::endl;
        
        auto valueArray = talk["value"];
        
        for (auto& v:valueArray.array_items()) {
            
            std::cout << v["msgNewCount"].string_value() <<std::endl;
            std::cout << v["msgCount"].string_value() <<std::endl;
        }
    }
    
    
    
//    json11::Json name = "xugang",age = 30;
//    
//    json11::Json arr;
//    
//    json11::Json jnull; // creates a null Json object.
//    json11::Json jtrue = true, pi = 3.14, str = "Hello";  // scalar objects
//    json11::Json arr { 1, 2, str };   // array object, using initializer list
//    arr << false;  // do you prefer 'push_back' ?
    
    //json11::Json user;
    
    Json my_json = Json::object {
        { "key1", "value1" },
        { "key2", false },
        { "key3", Json::array { 1, 2, 3 } },
    };
    std::string json_str = my_json.dump();
    
    std::cout << json_str << endl;
    
   
    
    
    
    
    
    

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
    //TestPTR();
    Testjson();
    std::cout << calc:: add(5, 5) << endl;
    
    
  return 0;
}
