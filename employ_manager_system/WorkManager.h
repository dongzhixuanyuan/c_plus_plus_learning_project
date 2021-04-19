//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_WORKMANAGER_H
#define PRACTICE_PROJECT_WORKMANAGER_H

#include <vector>
#include <algorithm>
#include "BaseWorker.h"
#include "Emploee.h"
#include "Manager.h"
#include "Boss.h"
using std::vector;
class WorkManager {
public:
    WorkManager();
    ~WorkManager();
    int workerNum = 0;
    vector<BaseWorker*>* workers;
    void showWorker();
    void addWorker();
    void deleteWorker();
    void modifyWorker(int id);
    BaseWorker* queryWorker(int id);

    void showReminder();


    static WorkManager& getInstance() {
        static WorkManager workManager;
        return workManager;
    }
    //    todo 文件操作

};


#endif //PRACTICE_PROJECT_WORKMANAGER_H
