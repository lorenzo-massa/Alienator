//
// Created by Lorenzo Massa on 30/05/2020.
//


#include "MapFactory.h"

std::shared_ptr<std::basic_ifstream<char>> MapFactory::openFile(std::string filename) {
    std::shared_ptr<std::basic_ifstream<char>> file = std::make_shared<std::ifstream>(filename);
    if(file->is_open()) {
        std::cout << filename << " is opened!" << std::endl;
        return file;
    }
    else
        std::cerr<<"File not found!"<<std::endl;
    return nullptr;
}
