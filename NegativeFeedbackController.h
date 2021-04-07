//
// Created by liudong on 2021/4/2.
//

#ifndef PRACTICE_PROJECT_NEGATIVEFEEDBACKCONTROLLER_H
#define PRACTICE_PROJECT_NEGATIVEFEEDBACKCONTROLLER_H

#include "OperateRecord.h"
#include <ctime>
#include <memory>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class NegativeFeedbackController {
private:
    std::shared_ptr<OperateRecord> operateRecord;
    unsigned short today;
    time_t timeStamp = time(0);

    NegativeFeedbackController &operator=(const NegativeFeedbackController &) = delete;

    NegativeFeedbackController();

    NegativeFeedbackController(const NegativeFeedbackController &) = delete;

    ~NegativeFeedbackController();

public:

    bool doFeedback(string postId);

    void resetReportRecord();

    static const string FILE_PATH_OF_REPORT_RECORD;

    static NegativeFeedbackController &getInstance() {
        static NegativeFeedbackController instance;
        return instance;
    }

};


#endif //PRACTICE_PROJECT_NEGATIVEFEEDBACKCONTROLLER_H
