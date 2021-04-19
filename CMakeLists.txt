cmake_minimum_required(VERSION 3.17)
project(practice_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(practice_project json.hh main.cpp OperateRecord.cpp
        OperateRecord.h
        NegativeFeedbackController.cpp
        NegativeFeedbackController.h
        util/Util.cpp util/Util.h
        tmpTest/Foo.cpp tmpTest/Foo.h
        employ_manager_system/WorkManager.cpp
        employ_manager_system/WorkManager.h
        employ_manager_system/BaseWorker.cpp
        employ_manager_system/BaseWorker.h
        employ_manager_system/Emploee.cpp
        employ_manager_system/Emploee.h
        employ_manager_system/Manager.cpp
        employ_manager_system/Manager.h
        employ_manager_system/Boss.cpp
        employ_manager_system/Boss.h)