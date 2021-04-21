//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_BASEWORKER_H
#define PRACTICE_PROJECT_BASEWORKER_H

#include <string>
#include <iostream>

#include "../json.hh"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using json = nlohmann::json;
namespace WorkerManageSys {
    enum class WorkerType {
        Employee, Manager, Boss
    };

//定义下WorkerType的输出流
    ostream &operator<<(ostream &os, const WorkerType &workerType);


    class BaseWorker {
    public:
        int id;
        string name;
        WorkerType type;

        BaseWorker();

        BaseWorker(int id, string name, WorkerType workerType);

        ~BaseWorker();

        virtual void doWork() {

        };

        string toString();

        json toJson();

    };

}


#endif //PRACTICE_PROJECT_BASEWORKER_H
