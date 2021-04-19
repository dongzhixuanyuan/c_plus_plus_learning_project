//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_BOSS_H
#define PRACTICE_PROJECT_BOSS_H
#include "BaseWorker.h"

class Boss : public BaseWorker {
public:
    Boss();
    void doWork() override;
};


#endif //PRACTICE_PROJECT_BOSS_H
