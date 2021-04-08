//
// Created by liudong on 2021/4/7.
//

#include "Foo.h"

Foo::Foo() {
    cout << "调用了Foo的构造函数" << endl;
}

Foo::~Foo() {
    cout << "调用了Foo的析构函数" << endl;
}

FooContainer::FooContainer(shared_ptr<vector<Foo>> ptr) : fooPtr(ptr) {
    cout << "调用了FooContainer的构造函数" << endl;
}

FooContainer::~FooContainer() {
    cout << "调用了FooContainer的析构函数" << endl;
}

void FooContainer::validateSharedPoint() {
    cout << "智能指针计数数量: " << fooPtr.use_count() << endl;
}