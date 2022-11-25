#include <cassert>
#include <iostream>
#include <math.h>
#include "SimpleInterest.h"

using namespace std;

int main(){
    SimpleInterest s;
    assert(abs(s.getSimpleInterest(1, 5, 1000) - 50) < 1e-9);
    assert(abs(s.getSimpleInterest(2, 5, 1000) - 100) < 1e-9);
    assert(abs(s.getSimpleInterest(3, 5, 1000) - 150) < 1e-9);
    return EXIT_SUCCESS;
}