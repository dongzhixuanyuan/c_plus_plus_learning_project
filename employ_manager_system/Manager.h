//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_MANAGER_H
#define PRACTICE_PROJECT_MANAGER_H

#include "BaseWorker.h"

namespace WorkerManageSys {
    class Manager : public BaseWorker {
    public:
        Manager();

        Manager(int id, string name, WorkerType workerType = WorkerType::Manager);

        void doWork() override;
    };

}


#endif //PRACTICE_PROJECT_MANAGER_H
