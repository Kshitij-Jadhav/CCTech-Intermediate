#include "sort_string_by_length.h"
#include <fstream>

int main(int argc, char *argv[]) {
    if(argc == 1)
    {
        cout << '\n';
    }
    else
    {
        ifstream file;
        file.open(argv[1], ios::in);
        if(!file.is_open())
        {
            cerr << "sort: cannot read: " << argv[1] << " : No such file or directory ";
            exit(EXIT_FAILURE);
        }
        string word;
        vector<string> words;
        while (file >> word) {
            words.push_back(word);
            sortStringByLength(words);
        }  
    }
    return EXIT_SUCCESS;
}