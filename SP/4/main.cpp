#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void copy_file(string path_src_file, string path_dst_file){
    char* buffer = new char;
 
    ifstream infile(path_src_file, ios::binary);
    ofstream outfile(path_dst_file, ios::binary);
    
    while (!infile.eof()){
        infile.read(buffer, sizeof(char));
        outfile.write(buffer, sizeof(char));
    }
 
    delete buffer;
}

int main(int argc, char const *argv[])
{
	string path_src_file = argv[0];
	string path_dst_file = argv[1];
	copy_file(path_src_file, path_dst_file);
	return 0;
}