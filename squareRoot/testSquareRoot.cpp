#include <cassert>
#include "squareRoot.h"

int main(){
    assert(abs(squareRoot(4) - 2) < 1e-9);
    assert(abs(squareRoot(0) - 0) < 1e-9);
    assert(abs(squareRoot(2) - 1.41421356237) < 1e-9);
    assert(squareRoot(-1) == 1);
}