//
// Created by liudong on 2021/4/2.
//

#include "NegativeFeedbackController.h"
#include "util/Util.h"

const string NegativeFeedbackController::FILE_PATH_OF_REPORT_RECORD = "report_record.txt";

NegativeFeedbackController::NegativeFeedbackController() {
    tm *ltm = localtime(&timeStamp);
    today = ltm->tm_mday;
    string cacheStr = Util::readStringFromFile(FILE_PATH_OF_REPORT_RECORD);
    if (!cacheStr.empty()){
        operateRecord = std::make_shared<OperateRecord>(OperateRecord::fromJson(cacheStr));
    } else {
        operateRecord = std::make_shared<OperateRecord>();
    }
    cout << "times:" << operateRecord->mTime <<  "，day: " << operateRecord->mDay << endl;
    std::for_each(operateRecord->reportIds->begin(), operateRecord->reportIds->end(), [](const auto &i) {
        cout << i << " ";
    });
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
        operateRecord->saveToFile(FILE_PATH_OF_REPORT_RECORD);
        return true;
    } else {
        if (operateRecord->mTime < 5) {
            vector<string>::iterator it = find(operateRecord->reportIds->begin(), operateRecord->reportIds->end(),
                                               postId);
            if (it == operateRecord->reportIds->end()) {
                operateRecord->mTime++;
                operateRecord->reportIds->push_back(postId);
                operateRecord->saveToFile(FILE_PATH_OF_REPORT_RECORD);
            }
            return true;
        } else {
            cout << "标记次数有点多，明天再试" << std::endl;
            return false;
        }
    }
}

void NegativeFeedbackController::resetReportRecord() {
    OperateRecord record;
    record.saveToFile(FILE_PATH_OF_REPORT_RECORD);
}
