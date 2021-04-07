//
// Created by liudong on 2021/4/2.
//

#include "OperateRecord.h"

#include <memory>

OperateRecord::OperateRecord() {
    mTime = 0;
    time_t timeStamp = time(0);
    tm *ltm = localtime(&timeStamp);
    mDay = ltm->tm_mday;
    reportIds = std::make_shared<vector<string>>();
}

OperateRecord::OperateRecord(const OperateRecord &src) {
    mTime = src.mTime;
    mDay = src.mDay;
    reportIds = src.reportIds;
}

OperateRecord::OperateRecord(int time, short month, std::shared_ptr<vector<string>> reportIds) : mTime(time),
                                                                                                 mDay(month),
                                                                                                 reportIds(reportIds) {

}

json OperateRecord::toJson() {
    json jReportIds(*reportIds.get());
    json result;
    result["time"] = mTime;
    result["day"] = mDay;
    result["reportIds"] = jReportIds;
    return result;
}

OperateRecord OperateRecord::fromJson(string &jsonStr) {
    OperateRecord record;
    try {
        json j = json::parse(jsonStr);
        if (!j.empty()) {
            record.mTime = j["time"];
            record.mDay = j["day"];
            std::vector<string> reportIdsString = j["reportIds"].get<std::vector<string>>();
            record.reportIds = std::make_shared<std::vector<string>>(reportIdsString);
        }
    } catch (json::parse_error& error ){
        std::cerr << error.what() << std::endl;
    }
    return record;
}

void OperateRecord::saveToFile(const string &path) {
    std::ofstream o;
    o.open(path, std::ios::trunc);
    if (o.is_open()){
        o << std::setw(4) << toJson() << std::endl;
    }
}
