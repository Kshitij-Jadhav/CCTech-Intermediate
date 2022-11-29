#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    char c;
    if (argc == 1) {
        cout << "\n";
    }
    else if (argc > 1) {
        string line;
        vector<string> lines;
        int count = 0;
        for (int i = 1; i < argc; i++) {
            ifstream infile(argv[i]);
            if (!infile) {
                cout << "sort: cannot read: " << argv[i] << " : No such file or directory ";
                count++;
                break;
            }
            else {
                while (getline(infile, line)) {
                    lines.push_back(line);
                }
            }
        }
        if (count == 0) {
            sort(lines.begin(), lines.end());
            for (int j = 0; j < lines.size(); j++)
                cout << lines.at(j) << endl;
        }
        
    }
}