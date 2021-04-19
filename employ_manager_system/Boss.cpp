//
// Created by liudong on 2021/4/9.
//

#include "Boss.h"

Boss::Boss():BaseWorker() {
    type = WorkerType::Boss;
}

void Boss::doWork() {
    cout << "Boss plan work" << endl;
}