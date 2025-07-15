    #include "repository.h"
    #include <filesystem>
    #include <iostream>
    #include <fstream>

    Repository::Repository(const std::string& path){

        workTree = path;
        gitDirectory = std::filesystem::path(path) / ".wyag";

    }

    std::string Repository::git_path(const std::string& subpath) const{

        return (std::filesystem::path (gitDirectory) / subpath).string();

    }

    void Repository::init(){
        if(std::filesystem::exists(gitDirectory)){
            std::cout << "Repository already exists at " << gitDirectory << std::endl;
        }

        std::filesystem::create_directories(std::filesystem::path(gitDirectory) / "objects");
        std::filesystem::create_directories(std::filesystem::path(gitDirectory) / "refs");
    
        std::ofstream config_file(std::filesystem::path(gitDirectory) / "config");
        config_file << "[core]\n";
        config_file << "\trepositoryformatversion = 0\n";
        config_file << "\tfilemode = true\n";
        config_file << "\tbare = false\n";
        config_file.close();

        std::filesystem::create_directories(std::filesystem::path(gitDirectory) / "refs" / "heads" / "master");

        std::ofstream head_file(std::filesystem::path(gitDirectory)/"HEAD");
        head_file << "ref: refs/heads/master\n";
        head_file.close();

        std::ofstream master_ref(std::filesystem::path(gitDirectory)/ "refs" / "heads" / "master");
        master_ref.close();

        
        std::cout << "Initialized empty WYAG repository in " << gitDirectory << std::endl;

        

    }