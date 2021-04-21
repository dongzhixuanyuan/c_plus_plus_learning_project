//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_EMPLOEE_H
#define PRACTICE_PROJECT_EMPLOEE_H
#include "BaseWorker.h"


namespace WorkerManageSys {
    class Employee: public BaseWorker {
    public:
        Employee();
        Employee(int id, string name,WorkerType type = WorkerType::Employee);

        void doWork() override;

    };
}


#endif //PRACTICE_PROJECT_EMPLOEE_H
