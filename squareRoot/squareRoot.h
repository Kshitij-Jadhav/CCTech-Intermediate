#include <math.h>
#include <cerrno>
#include <cstring>
#include <iostream>

using namespace std;

double squareRoot(double number){
    try {
        errno = 0;
        double result = sqrt(number);
        if(errno != 0){
            throw strerror(errno);
        }
        return result;
    }
    catch(char* e){
        cout << e << endl;
        exit(errno);
    }
}