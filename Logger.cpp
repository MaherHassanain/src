//
// Created by gorilla on 2019-11-25.
//

#include "Logger.h"

Logger::Logger() {
    fout.open("log.txt");
    fout << "DEFAULT LOG FILE" << endl;
}

Logger::Logger(string s) {
    fout.open(s);
    fout << s << endl;
}

void Logger::addEvent(string e){
    //fout << get_time() <<" : "<< e << endl;
    fout << e <<" @" << get_time()<<endl;
}

void Logger::closeFile(){
    fout.close();
}

char* Logger::get_time(){
    now = time(0);
    dt = ctime(&now);
    return dt;
}
