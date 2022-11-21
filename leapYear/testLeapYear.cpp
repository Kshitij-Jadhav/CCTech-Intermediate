#include <iostream>
#include "isLeapYear.h"
bool test();


int main (void){
    if(!test()){
        std :: cerr << "test failed" << std :: endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

bool test(){
    if(!isLeapYear(2000)){
        return false;
    }
    if(isLeapYear(2002)){
        return false;
    }
    if(!isLeapYear(4)){
        return false;
    }
    if(isLeapYear(100)){
        return false;
    }
    if(!isLeapYear(400)){
        return false;
    }
    std :: cout << "All test were successful" << std :: endl;
    return true;
}

