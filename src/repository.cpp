#include "repository.h"
#include <filesystem>

Repository::Repository(const std::string& path){

    workTree = path;
    gitDirectory = std::filesystem::path(path) / ".git";

}

std::string Repository::git_path(const std::string& subpath) const{

      return (std::filesystem::path (gitDirectory) / subpath).string();

}