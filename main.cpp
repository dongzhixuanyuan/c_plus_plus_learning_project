#include <iostream>
#include <thread>
#include <chrono>
#include "NegativeFeedbackController.h"
#include "json.hh"
#include "tmpTest/Foo.h"
#include "employ_manager_system/WorkManager.h"

using json = nlohmann::json;
int myCount = 0;

//负反馈功能。涉及的程序功能点为：
// 1、object与json之间的互转，json转为string后的持久存储，从文件中读取string，并将string转为json格式的对象。
// 2、智能指针share_ptr的使用。
void negativeFeedbackTest() {
    while (myCount <= 5) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        bool fbResult = NegativeFeedbackController::getInstance().doFeedback(std::to_string(time(0)));
        if (fbResult) {
            cout << "反馈成功" << endl;
        } else {
            cout << "反馈失败" << endl;
//            NegativeFeedbackController::getInstance().resetReportRecord();
        }
        myCount++;
    }
}

FooContainer testSharePtr() {
//    不能把栈上分配的对象赋值给share_ptr.因为在栈上分配对象后，函数调用完后会调用析构函数，但是这个时候如果仍然有share_ptr指向这个栈上分配的变量，
//    会导致野指针。
    shared_ptr<vector<Foo>> foo(new vector<Foo>);
    Foo *f = new Foo;
    foo->push_back(*f);
    FooContainer fooContainer(foo);
    return fooContainer;
}

void rightValueTest() {
    Foo f;
    asm("nop");
    Foo &&rf = std::move(f);
    asm("nop");

}

void workManageSystemTest() {
    WorkManager &manager = WorkManager::getInstance();
    manager.showReminder();
    while (true) {
        int operation = -1;
        cin >> operation;
        switch (operation) {
            case 0:
                manager.showWorker();
                break;
            case 1:
                manager.addWorker();
                break;
            case 2:
                manager.deleteWorker();
                break;
            case 3:
//            manager.queryWorker();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
        manager.showReminder();
    }
}


int main() {
//    std::thread t(negativeFeedbackTest);
//    t.join();
//    FooContainer container = testSharePtr();
//    container.validateSharedPoint();
//    rightValueTest();
    workManageSystemTest();

    system("read -n 1 -s -p \"Press any key to continue...\"");
    return 0;
}



