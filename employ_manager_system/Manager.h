//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_MANAGER_H
#define PRACTICE_PROJECT_MANAGER_H

#include "BaseWorker.h"

class Manager : public BaseWorker {
public:
    Manager();
//    Manager(int id, string &name, WorkerType &workerType) : BaseWorker(id, name, workerType) {}

    void doWork() override;
};


#endif //PRACTICE_PROJECT_MANAGER_H
