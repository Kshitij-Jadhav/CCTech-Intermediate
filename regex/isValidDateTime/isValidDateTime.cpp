#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char* argv[]){
    string year = "[0-9]+";
    string month = "(0[1-9]|1[0-2])";
    string day = "(0[1-9]|[12][0-9]|3[01])";
    string hour = "([01][0-9]|2[0-3])";
    string minute = "([0-5][0-9])";
    string second = "([0-5][0-9])";
    string miliSecond = "([0-9]*)";

    regex dateTimePattern(year + "-" + month + "-" + day + "T" 
                        + hour + ":" + minute + "(:" + second + ")?" + "(" + "\\." + miliSecond + ")?" 
                        + "(" + "Z" + ")?" + "(" + "\\+05:30" + ")?");

    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        smatch m;
        if (regex_match(arg, m, dateTimePattern)) {
            cout << arg << " is a valid date." << endl;
        } else {
            cout << arg << " is not a valid date." << endl;
            return 1;
        }
    }
}