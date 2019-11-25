//
// Created by screwdriver on 2019-11-24.
//

#ifndef SRC_MESSAGE_H
#define SRC_MESSAGE_H

#include <vector>
#include <string>

using namespace std;

class Message {

private:
    int ID; //aircraft ID or operator
    vector<string> msg;

public:
    Message();

    void setMsg(string s);
    vector<string> getMsg();

    void setID(int id);
    int getID();
};


#endif //SRC_MESSAGE_H
