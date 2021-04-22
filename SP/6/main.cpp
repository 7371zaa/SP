#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex cout_mutex;

void copy_file(string path_src_file, string path_dst_file)
{
    char* buffer = new char;
    ifstream infile(path_src_file, ios::binary);
    ofstream outfile(path_dst_file, ios::binary);
    
    while (!infile.eof())
    {
        infile.read(buffer, sizeof(char));
        outfile.write(buffer, sizeof(char));
    }
 
    cout_mutex.lock();
    cout << "Copied " << path_src_file << " to " << path_dst_file << endl;
    cout_mutex.unlock();
 
    delete buffer;
}

int main(int argc, char const *argv[])
{
    string path_from = argv[1];
    string path_to = argv[2];
    
    vector<thread> th_handlers;

    for (const auto & entry : filesystem::directory_iterator(path_from))
    {
        string filename = entry.path().filename();

        if (filesystem::is_directory(entry.symlink_status()))
        {
            cout << filename << " is directory, skipping" << endl;
            continue;
        }

        string copy_from = path_from + '/'+ filename;
        string copy_to = path_to + '/'+ filename;

        th_handlers.push_back
        (
            thread
            (
                copy_file,
                copy_from,
                copy_to
            )
        );

    }

    for (int i = 0; i < th_handlers.size(); ++i)
        th_handlers[i].join();
	return 0;
}