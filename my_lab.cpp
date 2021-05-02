#include "my_lab.hpp"
#include <iostream>
#include <string>
#include <cstring>
#define DEFEAT 5
char *replace( char *str, const char *f, const char *t ) {
   char *tmpPtr = strstr( str, f );
   
   if ( tmpPtr != 0 && strlen( f ) >= strlen( t )) {
      std::size_t sizeDiff = strlen( f ) - strlen( t );
      
      strncpy( tmpPtr, t, strlen( t ));
      
      if ( sizeDiff > 0 )
         for ( tmpPtr += strlen( t ); *tmpPtr != '\0'; tmpPtr++ )
            *tmpPtr = *( tmpPtr + sizeDiff );
      
   } else
      return 0;
   
   return str;
}
void deleteComments(std::ifstream& file,std::ofstream& fileo){
    bool inComment = false;
    bool inQuote = false;
    char* buff = new char[800];
    int i = 0;
    int j = 0;
    while(true){
        j++;
        if(j == 1000)
            break;
        file.getline(buff,800);
        if(file.eof())
            break;
        
        while(buff[i] != '\0' && buff[i] != '\n'){
            if(buff[i] == '\"' && inQuote && !inComment){
                inQuote = false;
             }
            if ((buff[i] == '\"')&& !inComment){
                inQuote = true;    
            } 
            if(buff[i] == '/' && buff[i+1] == '/' && !inComment && !inQuote){
                break;
            }
            if(buff[i] == '/' && buff[i+1] == '*' && !inQuote)
                inComment = true;
            if(!inComment){
                fileo << buff[i];
                std::cout <<buff[i];
            }
            if(buff[i] == '*' && buff[i+1] == '/' && inComment && !inQuote){
                i++;
                inComment = false;
            }
           
            i++;
        }
        delete[] (buff);
        buff = new char[800];
        i = 0;
        if(!inComment)
            fileo << "\n";
    }
    fileo << "}\0";
}

void define(std::ifstream& file){
    bool inComment = false;
    bool inQuote = false;
    char* buff = new char[801];
    int i = 0;
    char* keyword;
    char* keyvalue;
    while(true){
        file.getline(buff,800);
        if(file.eof())
            break;
        if(buff[0] == '#' && buff[1] == 'd' && buff[2] == 'e' && buff[3] == 'f' && buff[4] == 'i' && buff[5] == 'n' && buff[6] == 'e' ){
                int k = 8;
                int temp = 0;
                keyword = new char[800];
                keyvalue = new char[800];
                while (buff[k] != ' ')
                {
                    keyword[temp] = buff[k];
                    temp++;
                    k++;
                }
                std::cout << strlen(keyword);
                temp = 0;
                k++;
                while (buff[k] != '\0' || buff[k] != ' ')
                {
                    keyvalue[temp++] = buff[k++];
                }
                k++;
                std::cout << "f";

            }
        while(buff[i] != '\0'){
            
            if(buff[i] == '\"' && inQuote && !inComment){
                inQuote = false;
            }
            if ((buff[i] == '\"')&& !inComment){
                inQuote = true;
            } 
            if(buff[i] == '/' && buff[i+1] == '/' && !inComment && !inQuote){
                break;
            }
            if(buff[i] == '/' && buff[i+1] == '*' && !inQuote)
                inComment = true;
            if(buff[i] == '*' && buff[i+1] == '/' && inComment && !inQuote){
                i++;
                inComment = false;
            }
            if(!strlen(keyword)){
                char* finded = strstr(buff,keyword);
                //if((*(finded-1)<'A') || ((*(finded-1) > 'Z') && (*(finded-1) < 'a')) || (*(finded-1) > 'z'))
                    
                   // if((*(finded+strlen(keyword))<'A') || ((*(finded+strlen(keyword)) > 'Z') && (*(finded+strlen(keyword)) < 'a')) || (*(finded+strlen(keyword)) > 'z'))
                      // replace(buff,keyword,keyvalue);
                /*for(int i = 0;i < strlen(buff);i++)
                    std::cout << buff[i];*/
                    break;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   

            i++;
        }
        delete[] (buff);
        buff = new char[801];
        i = 0;
    }
}
void define1(std::ifstream& file){
    char* buff = new char[801];
    int i = 0;
    char* keyword ;
    char* keyvalue ;
    while (true)
    {
        file.getline(buff,800);
        if(file.eof())
           break;
        if(buff[0] == '#' && buff[1] == 'd' && buff[2] == 'e' && buff[3] == 'f' && buff[4] == 'i' && buff[5] == 'n' && buff[6] == 'e' ){
                int k = 8;
                int temp = 0;
                keyword = new char[800];
                keyvalue = new char[800];
                while (buff[k] != ' ' )
                {
                    keyword[temp] = buff[k];
                    temp++;
                    k++;
                }
                temp = 0;
                k++;
                while (buff[k] != '\0' && buff[k] != ' ' && buff[k] != '\n')
                {
                    keyvalue[temp++] = buff[k++];
                }
                k++;
        }
        while(buff[i] != '\0' || buff[i] != '\n'){
            
                char* finded = strstr(buff,keyword);
                if( finded != nullptr && finded[0] != buff[0])
                //    if((*(finded-1)<'A') || ((*(finded-1) > 'Z') && (*(finded-1) < 'a')) || (*(finded-1) > 'z'))
                //      if((*(finded+strlen(keyword))<'A') || ((*(finded+strlen(keyword)) > 'Z') && (*(finded+strlen(keyword)) < 'a')) || (*(finded+strlen(keyword)) > 'z'))
                    replace(buff,keyword,keyvalue);
                for(int i = 0;i < strlen(buff);i++)
                    std::cout << buff[i];
                std::cout << "\n";
                break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
            i++;
        }
        delete[] (buff);
        buff = new char[801];
        i = 0;
    }
}