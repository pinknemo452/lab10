#include <iostream>
#include <fstream>
#include <cstring>
//#include <dirent.h>
#include "my_lab.hpp"
//gg

int main(){
    char pat[1000];
	
    fgets(pat, 999,stdin);
    get_files_from_folder(pat);
    std::ifstream file("main.cpp");
    std::ofstream fileo("new1.c");
    delete_comments(file,fileo);
    fileo.close();
    return 0;
}