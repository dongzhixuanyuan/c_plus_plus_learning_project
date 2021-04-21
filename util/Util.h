//
// Created by liudong on 2021/4/7.
//

#ifndef PRACTICE_PROJECT_UTIL_H
#define PRACTICE_PROJECT_UTIL_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


struct ModeSelect {
    unsigned int numForSelect;
    string reminder;
    ModeSelect(int numForSelect,string reminder ):numForSelect(numForSelect),reminder(reminder){};
    ModeSelect(int numForSelect,char * reminder) {
        this->numForSelect = numForSelect;
        this->reminder = string(reminder);
    }
};

class Util {
public:
    static string readStringFromFile(const string &path);
    static int inputInt(vector<ModeSelect>&& options);
    static int getInputInt();
    static string getInputString();

};


#endif //PRACTICE_PROJECT_UTIL_H
