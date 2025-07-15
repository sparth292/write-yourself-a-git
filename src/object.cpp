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

    std::string header = "blob" + std::to_string(content.size()) + '\0';
    std::string full_data = header + content;

    unsigned char hash[SHA_DIGEST_LENGTH];

    SHA1(reinterpret_cast<const unsigned char*>(full_data.c_str()), full_data.size() , hash);

    std::ostringstream oss;

    for(int i = 0 ; i < SHA_DIGEST_LENGTH ; ++i){
       oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    std::string sha1 = oss.str();

    

}