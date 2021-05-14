#include <iostream>
#include <fstream>
#include <cstring>
//#include <dirent.h>
#include "my_lab.hpp"


int main(){
    std::ifstream file("new.c");
    std::ofstream fileo("new1.c");
    delete_comments(file,fileo);
    fileo.close();
    std::ifstream file1("new1.c");
    define1(file1);
    return 0;
}