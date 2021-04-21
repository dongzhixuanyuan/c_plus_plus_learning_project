//
// Created by liudong on 2021/4/9.
//

#include "Boss.h"

namespace WorkerManageSys {
    Boss::Boss():BaseWorker() {
        type = WorkerType::Boss;
    }
    Boss::Boss(int id, string name, WorkerType type ):BaseWorker(id,name,type) {}
    void Boss::doWork() {
        cout << "Boss plan work" << endl;
    }
}

