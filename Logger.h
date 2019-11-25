//
// Created by gorilla on 2019-11-25.
//

#ifndef SRC_MASTER_LOGGER_H
#define SRC_MASTER_LOGGER_H
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Logger {

private:
    ofstream fout;
    time_t now;
    char* dt;
    char* get_time();

public:
    Logger();
    Logger(string s);
    void addEvent(string e);
    void closeFile();
};


#endif //SRC_MASTER_LOGGER_H
