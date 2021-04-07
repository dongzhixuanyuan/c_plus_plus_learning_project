//
// Created by liudong on 2021/4/2.
//

#ifndef PRACTICE_PROJECT_OPERATERECORD_H
#define PRACTICE_PROJECT_OPERATERECORD_H
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include "json.hh"
using std::vector;
using std::string;
using nlohmann::json;
class OperateRecord {
private:
public:
    OperateRecord(int time, short month, std::shared_ptr<vector<string>> reportIds);
    OperateRecord();

    OperateRecord(const OperateRecord &);

    unsigned short mDay;
    unsigned int mTime;
    std::shared_ptr<vector<string>> reportIds;

    json toJson();
    static OperateRecord fromJson(string& json);

    void saveToFile(const string &path);

};


#endif //PRACTICE_PROJECT_OPERATERECORD_H
