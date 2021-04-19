//
// Created by liudong on 2021/4/9.
//

#include "Emploee.h"

Employee::Employee():BaseWorker() {
    this->type = WorkerType::Employee;
}

void Employee::doWork() {
    cout << "Do work for Manager" << endl;
}