//
// Created by liudong on 2021/4/2.
//

#include "NegativeFeedbackController.h"

NegativeFeedbackController::NegativeFeedbackController() {
    int times = 0;
    tm *ltm = localtime(&timeStamp);
    today = ltm->tm_mday;
//   todo 从文件中读取上次的信息
    std::shared_ptr<vector<string>> reportIds(new vector<string>());
    reportIds.get()->push_back("333");
    reportIds.get()->push_back("555");
    operateRecord = std::make_shared<OperateRecord>(times, today, reportIds);
}


NegativeFeedbackController::~NegativeFeedbackController() {

}

bool NegativeFeedbackController::doFeedback(string postId) {
    time_t now = time(0);
    tm *curTime = localtime(&now);
    if ((now - timeStamp) >= 8 * 60 * 60 * 1000) {
        today = curTime->tm_mday;
        timeStamp = now;
    }
    if (today != operateRecord.get()->mDay) {
        if (curTime->tm_hour < 8) {
            std::cout << "标记次数超过限制" << std::endl;
            return false;
        }
        std::shared_ptr<vector<string>> reportIds(new vector<string>());
        reportIds->push_back(postId);
        operateRecord = std::make_shared<OperateRecord>(0, today, reportIds);
        operateRecord->mTime++;
//        todo 保存到文件
        operateRecord->saveToFile("report_record.txt");
        return true;
    } else {
        if (operateRecord->mTime < 5) {
            vector<string>::iterator it = find(operateRecord->reportIds->begin(), operateRecord->reportIds->end(),
                                               postId);
            if (it == operateRecord->reportIds->end()) {
                operateRecord->mTime++;
                operateRecord->reportIds->push_back(postId);
//                todo 保存到文件
                operateRecord->saveToFile("report_record.txt");
            }
            return true;
        } else {
            cout << "标记次数有点多，明天再试" << std::endl;
            return false;
        }
    }
}

void NegativeFeedbackController::resetReportRecord() {
//        todo 清理存储的文件
}
