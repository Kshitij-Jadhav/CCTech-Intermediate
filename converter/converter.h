#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

union Data{
    float floatNumber;
    unsigned char bytes[4];
}ob;

std::stringstream converter(int op, float inputFloat,unsigned char inputBytes[4]){
    std::stringstream result;
    if(op == 1) {
        ob.floatNumber = inputFloat;
        for(int i = 0; i < 4; i++)
            result << ob.bytes[i] << " ";
        std::string temp ;
        result >> temp;
    }
    else {
        for(int i = 0; i < 4; i++)
            ob.bytes[i] = inputBytes[i];
        result << ob.floatNumber;
    }
    return result;
}