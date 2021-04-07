//
// Created by liudong on 2021/4/7.
//

#include "Util.h"
string Util::readStringFromFile(const string &path) {
    std::ifstream ifstream(path);
    if (ifstream.is_open()){
        std::string str((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
        ifstream.close();
        return str;
    }
    return "";
}