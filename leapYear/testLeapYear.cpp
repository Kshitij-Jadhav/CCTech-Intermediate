#include <iostream>
#include "isLeapYear.h"
#include <cassert>
bool test();


int main (void){
    assert(isLeapYear(4));
    assert(!isLeapYear(100));
    assert(isLeapYear(400));
    assert(isLeapYear(2000));
    assert(!isLeapYear(2002)); 
    return EXIT_SUCCESS;
}
