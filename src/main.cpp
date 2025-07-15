#include <iostream>
#include "repository.h"
#include "utils.h"

int main(int argc, char* args[]){
    
    Repository repo("/home/parth/Desktop/write-yourself-a-git/");

    std::cout << "Config Path " << repo.git_path("config") << std::endl;    
    
    std::string timestamp = get_timestamp_with_timezone();
    
    std::cout << "Current timestamp: " << timestamp << std::endl;

    if(argc > 2){
    
        std::cerr << "Usage of wyag <commands>";
    
    }

    std::string cmd = args[1];

    if(cmd == "init"){
        Repository repo(".");
        repo.init();
    }
    else{
        std::cerr << "Unknown Command : " << cmd << std::endl;
    }

    return 0;
}