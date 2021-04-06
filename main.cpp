#include <iostream>
#include <thread>
#include <chrono>
#include "NegativeFeedbackController.h"
#include "json.hh"
using json = nlohmann::json;
int count = 0;
void test01(){
    while (count <=  3) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        json j;
        j["pi"] = 3.41;
        NegativeFeedbackController::getInstance().doFeedback(std::to_string(time(0)));
        count++;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;


    std::thread t(test01);
    t.join();
//    char a;
//    cin>>a;
    return 0;
}



