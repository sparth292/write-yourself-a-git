#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <string>

class Repository{
     public:
     std::string workTree;
     std::string gitDirectory;

     Repository(const std::string& path);
     
     
     std::string git_path(const std::string& subpath) const;




};

#endif  