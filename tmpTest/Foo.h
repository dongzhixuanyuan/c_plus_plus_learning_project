//
// Created by liudong on 2021/4/7.
//

#ifndef PRACTICE_PROJECT_FOO_H
#define PRACTICE_PROJECT_FOO_H
#include <string>
#include <iostream>
#include <memory>
using namespace std;
class Foo {
public:
    ~Foo();
    Foo();
    int value= 0 ;
};

class FooContainer {
public:
    shared_ptr<vector<Foo>> fooPtr;
    FooContainer(shared_ptr<vector<Foo>> ptr);
    ~FooContainer();
    void validateSharedPoint();
};


#endif //PRACTICE_PROJECT_FOO_H
