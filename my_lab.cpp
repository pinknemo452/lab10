#include "my_lab.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>


void getDefine(const std::string& str, std::string& keyword, std::string& keyvalue,bool& flag) {
    if (str.length() < 7)
        return;
    if (str[0] == '#' && str[1] == 'd' && str[2] == 'e' && str[3] == 'f' && str[4] == 'i' && str[5] == 'n' && str[6] == 'e') {
        flag = true;
        int k = 8;
        int temp = 0;
        while (str[k] != ' ')
            k++;
        keyword = str.substr(8, k-8);
        const int kk = k;
        k++;
        while (str[k] != '\0' && str[k] != ' ' && str[k] != '\n')
            k++;
        keyvalue = str.substr(kk, k+1 - kk);

    }
}
string::string(const char* mes, const int length) {
    len_ = length;
    str_ = new char[length];
    for (int i = 0; i < len_; i++)
        str_[i] = mes[i];
}
string::~string() {
    delete[] str_;
}
char *replace( char *str, const char *f, const char *t ) {
   char *tmp_ptr = strstr( str, f );
   
   if ( tmp_ptr != nullptr && strlen( f ) >= strlen( t )) {
	   const std::size_t size_diff = strlen( f ) - strlen( t );
      
      strncpy( tmp_ptr, t, strlen( t ));
      
      if ( size_diff > 0 )
         for ( tmp_ptr += strlen( t ); *tmp_ptr != '\0'; tmp_ptr++ )
            *tmp_ptr = *( tmp_ptr + size_diff );
      
   } else
      return nullptr;
   
   return str;
}
void delete_comments(std::ifstream& file,std::ofstream& fileo){
    auto buff = new char[800];
    int i = 0;
    int j = 0;
    while(true){
        j++;
        if(j == 1000)
            break;
        file.getline(buff,800);
        if (file.eof()) {
            while (buff[i] != '\0' && buff[i] != '\n') {
                fileo << buff[i];
                i++;
            }
            break;
        }
        bool skip_qoute = false;
        bool in_comment = false;
        bool in_quote = false;
        while(buff[i] != '\0' && buff[i] != '\n'){
            if(buff[i] == '\"' && in_quote && !in_comment){
                in_quote = false;
                skip_qoute = true;
             }
            if ((buff[i] == '\"')&& !in_comment && !in_quote && !skip_qoute){
                in_quote = true;    
            }
            if (skip_qoute)
                skip_qoute = false;
            if(buff[i] == '/' && buff[i+1] == '/' && !in_comment && !in_quote){
                break;
            }
            if(buff[i] == '/' && buff[i+1] == '*' && !in_quote)
                in_comment = true;
            if(!in_comment){
                fileo << buff[i];
            }
            if(buff[i] == '*' && buff[i+1] == '/' && in_comment && !in_quote){
                i++;
                in_comment = false;
            } 
            i++;
        }
        delete[] (buff);
        buff = new char[800];
        i = 0;
        if(!in_comment)
            fileo << "\n";
    }
}


void define1(std::ifstream& file){
    std::string buff;
    int i = 0;
    bool new_define = false;
    while (true)
    {
	    std::string keyvalue;
	    std::string keyword;
	    getline(file,buff);
        if (file.eof()) {
            std::cout << buff.c_str();
            break;
        }
        getDefine(buff,keyword,keyvalue,new_define);
        while(buff[i] != '\0' && buff[i] != '\n'){
            if (!new_define && !keyword.empty()) {
	            const int keyf = buff.find(keyword);
                if (keyf != std::string::npos)
                    if (buff[keyf - 1] < 'A' || buff[keyf - 1] > 'Z' && buff[keyf - 1] < 'a' || buff[keyf - 1] > 'z')
                        if (buff[keyf + keyword.length()] < 'A' || buff[keyf + keyword.length()] > 'Z' && buff[keyf + keyword.length()] < 'a' || buff[keyf + keyword.length()] > 'z')
                           buff.replace(keyf, keyword.length(), keyvalue);
            }
            i++;
        }
        new_define = false;
        std::cout << buff;
        std::cout << "\n";
        i = 0;
    }
}





void recursive(std::filesystem::path path)
{
    try {
        for (auto& p : std::filesystem::directory_iterator(path)) {
            recursive(p.path());
        }
    }
    catch (std::filesystem::filesystem_error& a)
    {
        auto b =  a.what();
        if (a.path1().string().find(".cpp") != std::string::npos )
        {
            std::cout <<"Deleting from: " << a.path1() <<"\n";
            std::ifstream from(a.path1());
            std::ofstream to(a.path1().string().append("1"));
            delete_comments(from, to);
            from.close();
            to.close();
        }
    }
}
void get_files_from_folder(char* pathh)
{
    pathh[strlen(pathh) - 1] = '\0';
    recursive(std::string(pathh));
}