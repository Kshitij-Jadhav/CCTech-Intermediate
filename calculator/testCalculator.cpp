#include <cassert>
#include<math.h>
#include "calculator.h"

using namespace std;

main(){
    assert(abs(calculator(3.0, '+', 1.0).second - 4.0) < 1e-9 && calculator(3.0, '+', 1.0).first);
    assert(abs(calculator(3.0, '-', 1.0).second - 2.0) < 1e-9 && calculator(3.0, '+', 1.0).first);
    assert(abs(calculator(3.0, '*', 3.0).second - 9.0) < 1e-9 && calculator(3.0, '+', 1.0).first);
    assert(abs(calculator(3.0, '/', 3.0).second - 1.0) < 1e-9 && calculator(3.0, '+', 1.0).first);
    assert(abs(calculator(1, '+', 3).second - 4) < 1e-9 && calculator(3.0, '+', 1.0).first);
    assert(abs(calculator(-1, '+', -3).second - (-4)) < 1e-9 && calculator(3.0, '+', 1.0).first);
    return EXIT_SUCCESS;
}