//
// Created by liudong on 2021/4/9.
//

#include "WorkManager.h"

namespace WorkerManageSys {

    string WorkManager::filePath = "woker.text";

    WorkManager::WorkManager() {
        workerNum = 0;
        workers = new vector<BaseWorker *>;
        cout << "执行了WorkManager的构造函数" << endl;
        string cacheStr = Util::readStringFromFile(filePath);
        if (!cacheStr.empty()) {
            try {
                json result = json::parse(cacheStr);
                cout << result << endl;
                for (auto it = result.begin(); it != result.end(); it++) {
                    string type = (*it)["type"];
                    int id = (*it)["id"];
                    string name = (*it)["name"];
                    BaseWorker *worker;
                    if (type == "Employee") {
                        worker = new Employee(id, name);
                    } else if (type == "Manager") {
                        worker = new Manager(id, name);
                    } else if (type == "Boss") {
                        worker = new Boss(id, name);
                    }
                    workers->push_back(worker);
                    workerNum++;
                }
            } catch (nlohmann::detail::type_error &error) {
                cerr << error.what() << endl;
                remove(filePath.data());
            }
        }
    }

    WorkManager::~WorkManager() {
        cout << "执行了WorkManager的析构函数" << endl;
        std::for_each(workers->begin(),workers->end(),[](auto& wokerPtr ){
           delete wokerPtr;
        });
    }


    void WorkManager::showReminder() {
        cout << "*******请选择操作********" << endl;
        cout << "*******0、显示所有员工********" << endl;
        cout << "*******1、添加员工********" << endl;
        cout << "*******2、删除员工********" << endl;
        cout << "*******3、查询员工********" << endl;
        cout << "*******4、修改员工********" << endl;
        cout << "*******5、回到主界面********" << endl;
        cout << "*******6、退出程序********" << endl;

    }

    void WorkManager::addWorker() {
        BaseWorker *worker;
        int type = -1;
        cout << "请输入类型：" << endl;
        cin >> type;
        if (type == 0) {
            worker = new Employee;
        } else if (type == 1) {
            worker = new Manager;
        } else if (type == 2) {
            worker = new Boss;
        }
        int id = 0;
        cout << "请输入id: " << endl;
        cin >> id;
        worker->id = id;
        string name;
        cout << "请输入名字: " << endl;
        cin >> name;
        worker->name = name;
        workers->push_back(worker);
        workerNum++;
        saveToFile();
    }

    void WorkManager::deleteWorker() {
        cout << "请选择删除方式：0表示按照员工id删除；1表示按照yg姓名删除" << endl;
        int deleteMode = 0;
        cin >> deleteMode;
        if (deleteMode == 0) {
            cout << "请输入员工id" << endl;
            int eid;
            cin >> eid;
            if (workerNum > 0) {
                for (auto it = workers->begin(); it != workers->end(); it++) {
                    if ((*it)->id == eid) {
                        workers->erase(it);
                        workerNum--;
                    }
                }
            }
        } else if (deleteMode == 1) {
            cout << "请输入员工姓名" << endl;
            string name;
            cin >> name;
            if (workerNum > 0) {
                for (auto it = workers->begin(); it != workers->end(); it++) {
                    if ((*it)->name == name) {
                        workers->erase(it);
                        workerNum--;
                    }
                }
            }
        }
        saveToFile();
    }

    void WorkManager::modifyWorker(int id) {
        if (workerNum > 0) {
            for (auto it = workers->begin(); it != workers->end(); it++) {
                if ((*it)->id == id) {
                    BaseWorker *target = *it;
                    int type = -1;
                    cout << "请输入类型：" << endl;
                    cin >> type;
                    if (type == 0) {
                        target->type = WorkerType::Employee;
                    } else if (type == 1) {
                        target->type = WorkerType::Manager;
                    } else if (type == 2) {
                        target->type = WorkerType::Boss;
                    }
                    int id = 0;
                    cout << "请输入id: " << endl;
                    cin >> id;
                    target->id = id;
                    string name;
                    cout << "请输入名字: " << endl;
                    cin >> name;
                    target->name = name;
                }
            }
        }
    }

    BaseWorker *WorkManager::queryWorker() {
        int type = Util::inputInt({ModeSelect(0, "按照id进行查询"), ModeSelect(1, "按照姓名进行查询")});
        if (type == 0) {
            int id = Util::getInputInt();
            for (auto it = workers->begin(); it != workers->end(); it++) {
                if ((*it)->id == id) {
                    return *it;
                }
            }
        } else if (type == 1) {
            string name = Util::getInputString();
            for (auto it = workers->begin(); it != workers->end(); it++) {
                if ((*it)->name == name) {
                    return *it;
                }
            }
        }
        return nullptr;
    }


    void WorkManager::showWorker() {
        for (auto &item:*workers) {
            cout << item->id << " " << item->name << " " << item->type << endl;
        }
    }


    bool WorkManager::saveToFile() {
        std::ofstream f(filePath, std::ios::trunc);
        if (f.is_open()) {
            vector<string> v;
            for (auto &item:*workers) {
                v.push_back((*item).toJson());
            }
            json result(v);
            f << std::setw(4) << result << endl;
            f.close();
            return true;
        }
        return false;
    }


}



