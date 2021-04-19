//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_EMPLOEE_H
#define PRACTICE_PROJECT_EMPLOEE_H
#include "BaseWorker.h"


class Employee: public BaseWorker {
public:
     Employee();
//    Employee(int id, string &name, WorkerType &workerType):BaseWorker(id,name,workerType){};

    void doWork() override;

};


#endif //PRACTICE_PROJECT_EMPLOEE_H
