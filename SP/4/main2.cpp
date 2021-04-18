#include <string>
#include <iostream>
#include <filesystem>
#include <unistd.h>

using namespace std;

void run_copy_file_in_another_process(string path_src_file, string path_dst_file){
	if(fork() != 0)
		return;

	char* args[] = {
		(char*)path_src_file.c_str(),
		(char*)path_dst_file.c_str(),
		(char*)NULL
	};
	int res = execv(
		"1.elf",
		args
	);
}

int main(int argc, char const *argv[])
{
	string path_from = argv[1];
	string path_to = argv[2];

    for (const auto & entry : filesystem::directory_iterator(path_from)){
    	string filename = entry.path().filename();    	
        if (filesystem::is_directory(entry.symlink_status())){
            cout << filename << " is directory, skipping" << endl;
            continue;
        }

    	string copy_from = path_from + '/'+ filename;
    	string copy_to = path_to + '/'+ filename;
    	run_copy_file_in_another_process(copy_from, copy_to);
	    cout << filename << " copied from " << copy_from << " to " << copy_to << endl;
    }
}
