#include <iostream>
#include <thread>
#include <chrono>
#include "NegativeFeedbackController.h"
#include "json.hh"
using json = nlohmann::json;
int count = 0;
//负反馈功能。涉及的程序功能点为：
// 1、object与json之间的互转，json转为string后的持久存储，从文件中读取string，并将string转为json格式的对象。
// 2、智能指针share_ptr的使用。
void negativeFeedbackTest(){
    while (count <=  5) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        bool fbResult =  NegativeFeedbackController::getInstance().doFeedback(std::to_string(time(0)));
        if (fbResult) {
            cout << "反馈成功" << endl;
        } else {
            cout << "反馈失败" << endl;
            NegativeFeedbackController::getInstance().resetReportRecord();
        }
        count++;
    }
}

int main() {
    std::thread t(negativeFeedbackTest);
    t.join();
    return 0;
}



