#include "converter.h"
#include <cassert>

main(){
    unsigned char arr1[4] = {0,0,0,0};
    assert(converter(1,1.5,arr1).str() == "0 0 192 63");
}