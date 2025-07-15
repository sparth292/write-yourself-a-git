#include "object.h"
#include <zlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <openssl/sha.h>


std::string write_blob(std::string& filePath , std::string& objectDir){

    std::ifstream file(filePath , std::ios::binary);
    if(!file){
        throw std::runtime_error("File Cannot be opened" + filePath);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    file.close();

}