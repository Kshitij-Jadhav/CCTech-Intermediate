#include <cassert>
#include "isPrime.h"

using namespace std;

void test() {
    assert(!isPrime(-1));
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(!isPrime(4));
}

int main(void) {
    test();
}