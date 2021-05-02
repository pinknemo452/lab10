#include <iostream>
#include <fstream>
#include <cstring>
#include <dirent.h>
#include "my_lab.hpp"
#define DEFEAT 5


int main(){
    std::ifstream file;
    std::ofstream fileo("new.c");
    std::cout << "enter path ";
    char* path = new char[800];
    std::cin >> path; 
    DIR *dir;
    closedir(dir);
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
        for(int i = 0;i <3;i++){
            ent = readdir(dir);
            if(ent->d_name[1] == '.' || ent->d_name == ".." || ent == NULL || strchr(ent->d_name,'.') == NULL)
                continue;
            std::cout << ent->d_name << "\n";
            std::ofstream fileo("new.c");
            
            std::string buffer(ent->d_name);
            try{
            std::cout << strcat(strcat(path,"/"),buffer.c_str());
            std::ifstream file(strcat(strcat(path,"/"),buffer.c_str()));
            }
            catch (std::ifstream::failure e) {
                std::cerr << "Exception opening/reading/closing file\n";
             }
            char* sample = new char[1000];
            file.getline(sample,100);
            std::cout << sample;
            std::cout << file.exceptions();
            deleteComments(file,fileo);
            fileo.close();
            file.close();
        }
    }
    closedir (dir);
    fileo.close();
    std::ifstream file1("new.c");
    return 0;
}