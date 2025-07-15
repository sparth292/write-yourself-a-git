#include "object.h"
#include <zlib.h>
#include <vector>
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

    uLongf compressed_size = compressBound(full_data.size());
std::vector<unsigned char> compressed(compressed_size);

int z_result = compress(compressed.data(), &compressed_size,
                        reinterpret_cast<const Bytef*>(full_data.data()),
                        full_data.size());

if (z_result != Z_OK) {
    throw std::runtime_error("Compression failed");
}

    std::string dir = objectDir + "/" + sha1.substr(0, 2);
    std::string fileName = sha1.substr(2);
    std::filesystem::create_directories(dir);

 std::ofstream out(dir + "/" + fileName, std::ios::binary);
out.write(reinterpret_cast<const char*>(compressed.data()), compressed_size);
out.close();

    return sha1;
}