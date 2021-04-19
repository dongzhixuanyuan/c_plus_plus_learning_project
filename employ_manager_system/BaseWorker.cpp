//
// Created by liudong on 2021/4/9.
//

#include "BaseWorker.h"


BaseWorker::BaseWorker(int id, string &name, WorkerType &workerType):id(id),name(name),type(workerType) {

}

BaseWorker::BaseWorker() {
    this->id = -1;
    this->name = "";
    this->type = WorkerType::Employee;
}

ostream &operator<<(ostream &os, const WorkerType &workerType) {
    string content = "";
    switch (workerType) {
        case WorkerType::Employee:
            content = "Employee";
            break;
        case WorkerType::Manager:
            content = "Manager";
            break;
        case WorkerType::Boss:
            content = "Boss";
            break;
        default:
            break;
    }
    os << content << endl;
    return os;
}