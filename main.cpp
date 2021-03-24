#include "my_lab.hpp"
#include <iostream>
#include <fstream>

int main(){
    std::ifstream file("prog.c");
    deleteComments(file);
    return 0;
}