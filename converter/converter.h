#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

union Data{
    float floatNumber;
    unsigned char bytes[4];
}ob;

std::stringstream converter(int inputDataType, float inputFloat,unsigned char inputBytes[4]){
    std::stringstream result;
    if(inputDataType == 1) {
        ob.floatNumber = inputFloat;
        for(int i = 0; i < 4; i++)
            if(i == 0) {
                result << static_cast<int>(ob.bytes[i]);
            }
            else {
                result << " " << static_cast<int>(ob.bytes[i]) ;
            }
    }
    else {
        for(int i = 0; i < 4; i++)
            ob.bytes[i] = inputBytes[i];
        result << ob.floatNumber;
    }
    return result;
}