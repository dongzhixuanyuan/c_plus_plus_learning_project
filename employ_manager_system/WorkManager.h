//
// Created by liudong on 2021/4/9.
//

#ifndef PRACTICE_PROJECT_WORKMANAGER_H
#define PRACTICE_PROJECT_WORKMANAGER_H

#include <vector>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include <stdio.h>

#include "../util/Util.h"
#include "BaseWorker.h"
#include "Emploee.h"
#include "Manager.h"
#include "Boss.h"
#include "../json.hh"

using std::vector;
using std::fstream;


namespace WorkerManageSys {
    using json = nlohmann::json;
    using std::cerr;
    class WorkManager {
    public:
        WorkManager();

        ~WorkManager();

        int workerNum = 0;
        vector<BaseWorker *> *workers;

        void showWorker();

        void addWorker();

        void deleteWorker();

        void modifyWorker(int id);

        BaseWorker *queryWorker();

        void showReminder();

        bool saveToFile();

        static string filePath;

        static WorkManager &getInstance() {
            static WorkManager workManager;
            return workManager;
        }


        //    todo 文件操作

    };
}


#endif //PRACTICE_PROJECT_WORKMANAGER_H
