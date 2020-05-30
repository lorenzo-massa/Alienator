//
// Created by th3lo on 30/05/2020.
//


#include "MapFactory.h"

std::basic_ifstream<char> MapFactory::openFile(std::string filename) {
    std::ifstream file(filename);
    if(file.is_open()) {
        std::cout << filename << " is opened!" << std::endl;
        return file;
    }
    else
        std::cerr<<"File not found!"<<std::endl;
    return NULL;
}
