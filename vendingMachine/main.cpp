#include "VendingMachine.h"
#include <cassert>


int main() {
    VendingMachine m;
    assert(m.isValidCoin("dime"));
    assert(m.isValidCoin("quarter"));
    assert(m.isValidCoin("nickel"));
    assert(!m.isValidCoin("penny"));
    m.printOptions();
}
