//
// Created by screwdriver on 2019-11-24.
//

#include "Message.h"

Message::Message(){}
void Message::setMsg(string s){
    string delimiter = ",";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        msg.push_back (token);
    }
    msg.push_back (s.substr (pos_start));
}

vector<string> Message::getMsg() {
    return msg;
}


int Message::getID() {
    return ID;
}

void Message::setID(int id){
    ID = id;
};
