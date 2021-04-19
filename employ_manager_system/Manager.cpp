//
// Created by liudong on 2021/4/9.
//

#include "Manager.h"

Manager::Manager():BaseWorker() {
    this->type = WorkerType::Manager;
}


void Manager::doWork() {
    cout << "Do worke from Boss" << endl;
}