#include <iostream>
#include "repository.h"
#include "utils.h"

int main(int argc, char* args[]){
    
    Repository repo("/home/parth/Desktop/write-yourself-a-git/");

    std::cout << "Config Path " << repo.git_path("config") << std::endl;    
    
    std::string timestamp = get_timestamp_with_timezone();
    
    std::cout << "Current timestamp: " << timestamp << std::endl;

    return 0;
}