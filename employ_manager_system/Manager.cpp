//
// Created by liudong on 2021/4/9.
//

#include "Manager.h"

namespace WorkerManageSys {
    Manager::Manager():BaseWorker() {
        this->type = WorkerType::Manager;
    }


    void Manager::doWork() {
        cout << "Do worke from Boss" << endl;
    }

    Manager::Manager(int id, string name, WorkerType workerType) : BaseWorker(id, name, workerType) {

    }
}

