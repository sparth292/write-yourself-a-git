#include "object.h"
#include "repository.h"
#include "utils.h"
#include <iostream>

int main(int argc, char* args[]) {
    if (argc < 2) {
        std::cerr << "Usage: wyag <command> [args...]" << std::endl;
        return 1;
    }

    std::string cmd = args[1];

    if (cmd == "init") {
        Repository repo(".");
        repo.init();
    }
    else if (cmd == "hash-object") {
        if (argc < 3) {
            std::cerr << "Usage: wyag hash-object <file>" << std::endl;
            return 1;
        }

        std::string file_path = args[2];
        Repository repo(".");
        std::string sha1 = write_blob(file_path, repo.git_path("objects"));
        std::cout << sha1 << std::endl;
    }
    // ithe changes jhale aahet nntr ithun ach continue karayche aahe
    else if(cmd == "cat-file")
    {
        
    // ithe changes jhale aahet nntr ithun ach continue karayche aahe
         if(argc != 4 || std::string(args[2]) != "-p"){
            std::cerr << "Usage of wyag cat-file -p <sha1>" << std::endl;
            return 1;
         }
    }
    else {
        std::cerr << "Unknown Command : " << cmd << std::endl;
        return 1;
    }

    return 0;
}
