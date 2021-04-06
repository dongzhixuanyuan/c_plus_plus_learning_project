//
// Created by liudong on 2021/4/2.
//

#include "OperateRecord.h"

OperateRecord::OperateRecord() {

}

OperateRecord::OperateRecord(const OperateRecord &src) {
    mTime = src.mTime;
    mDay = src.mDay;
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
    json j = json::parse(jsonStr);
    OperateRecord record;
    record.mTime = j["time"];
    record.mDay = j["day"];
    std::vector<string> reportIdsString = j["reportIds"].get<std::vector<string>>();
    return record;
}

void OperateRecord::saveToFile(const string &path) {
    std::ofstream o;
    o.open(path, std::ios::trunc);
    if (o.is_open()){
        o << std::setw(4) << toJson() << std::endl;
    }
}

string OperateRecord::readFromFile(string &path) {
    std::ifstream ifstream(path);
    std::string str((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
    return str;

}