//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_BASEWORKER_H
#define PRACTICE_PROJECT_BASEWORKER_H

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
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
    BaseWorker(int id, string &name, WorkerType &workerType);
    virtual void doWork() = 0;
};


#endif //PRACTICE_PROJECT_BASEWORKER_H
