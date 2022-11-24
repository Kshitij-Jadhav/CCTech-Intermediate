#include <sstream>

using namespace std;

stringstream echo(int argc, string argv[]) {
    stringstream output;
    for (int i = 1; i < argc; i++) {
        if (i > 1) 
            output << " ";
        output << argv[i];
    }
    output << "\n";
    return output;
}