#include "my_lab.hpp"
#include <iostream>
void deleteComments(std::ifstream& file){
    bool inComment = false;
    char* buff = new char[800];
    int i = 0;
    while(true){
        file.getline(buff,800);
        if(file.eof())
            break;
        while(buff[i] != '\0'){
            if(buff[i] == '/' && buff[i+1] == '/' && !inComment)
                break;
            if(buff[i] == '/' && buff[i+1] == '*')
                inComment = true;
            if(!inComment)
                std::cout << buff[i];
            if(buff[i] == '*' && buff[i+1] == '/' && inComment){
                i++;
                inComment = false;
            }
            i++;
        }
        delete[] (buff);
        buff = new char[800];
        i = 0;
        if(!inComment)
            std::cout << "\n";
    }
}