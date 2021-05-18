#ifndef M
#define M
#include <fstream>
void delete_comments(std::ifstream& file,std::ofstream& fileo);
void define1(std::ifstream& file);
void get_files_from_folder(char* pathh);
class string {
	string() = default;
	string(const char* mes, int length);
private:
	char* str_;
	int len_;
	~string();
};
#endif