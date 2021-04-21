//
// Created by liudong on 2021/4/9.
//

#include "BaseWorker.h"


namespace WorkerManageSys {
    BaseWorker::BaseWorker(int id, string name, WorkerType workerType) : id(id), name(name), type(workerType) {

    }

    BaseWorker::~BaseWorker() {
        cout << "调用了BaseWorker的析构函数" << endl;
    }

    BaseWorker::BaseWorker() {
        this->id = -1;
        this->name = "";
        this->type = WorkerType::Employee;
    }


    string BaseWorker::toString() {
        string content = "";
        switch (this->type) {
            case WorkerType::Employee:
                content = "Employee";
                break;
            case WorkerType::Manager:
                content = "Manager";
                break;
            case WorkerType::Boss:
                content = "Boss";
                break;
            default:
                break;
        }
        return "id:" + std::to_string(this->id) + " name:" + this->name + content;
    }

    template<typename BasicJsonType>
    static void to_json(BasicJsonType &j, WorkerType workerType) {
        switch (workerType) {
            case WorkerType::Employee:
                j = "Employee";
                return;
            case WorkerType::Manager:
                j = "Manager";
                return;
            case WorkerType::Boss:
                j = "Boss";
                return;
            default:
                break;
        }
    }

    template<typename BasicJsonType>
    static void from_json(const BasicJsonType &j, WorkerType &workerType) {
        const auto str = j.template get<string>();
        const std::map<string, WorkerType> m = {
                {"Employee", WorkerType::Employee},
                {"Manager",  WorkerType::Manager},
                {"Boss",     WorkerType::Boss},

        };
        const auto it = m.find(str);
        workerType = it->second;
    }


    template<typename BasicJsonType>
    static void to_json(BasicJsonType &j, const BaseWorker &worker) {
        j = BasicJsonType({"id", worker.id}, {"name", worker.name}, {"type", worker.type});
    }

    template<typename BasicJsonType>
    static void from_json(const BasicJsonType &j, BaseWorker &worker) {
        worker.id = j["id"].template get<int>();
        worker.name = j["name"].template get<string>();
        worker.type = j["type"].template get<WorkerType>();
    }


    json BaseWorker::toJson() {
        json model;
        model["id"] = id;
        model["name"] = name;
        model["type"] = type;
        return model;
    }

    ostream &operator<<(ostream &os, const WorkerType &workerType) {
        string content = "";
        switch (workerType) {
            case WorkerType::Employee:
                content = "Employee";
                break;
            case WorkerType::Manager:
                content = "Manager";
                break;
            case WorkerType::Boss:
                content = "Boss";
                break;
            default:
                break;
        }
        os << content << endl;
        return os;
    }

}


