#include <iostream>
#include "repository.h"

int main(int argc, char* args[]){
    
    Repository repo("/home/parth/Desktop/write-yourself-a-git/");

    std::cout << "Config Path " << repo.git_path("config") << std::endl;    

    return 0;
}