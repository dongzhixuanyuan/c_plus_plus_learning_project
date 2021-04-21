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

int Util::inputInt(vector<ModeSelect> &&options) {
    std::for_each(options.begin(),options.end(),[](ModeSelect& modeItem){
        cout << modeItem.numForSelect << " : " << modeItem.reminder << endl;
    });

    while (true) {
        int select = -1;
        cin >> select;
        auto it = std::find_if(options.begin(), options.end(), [select](ModeSelect &modeItem) -> bool {
            if (modeItem.numForSelect == select) {
                return true;
            }
        });
        if (it != options.end()) {
            return it->numForSelect;
        }else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
}
int Util::getInputInt() {
    int tmp;
    cin >> tmp;
    return tmp;
}

string Util::getInputString() {
    string tmp;
    cin >> tmp;
    return tmp;
}