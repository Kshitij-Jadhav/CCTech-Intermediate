#include "closestToZero.h"
#include <cassert>
#include <iostream>

using namespace std;

main() {
    int arr1[2] = {-1,1};
    assert(closestToZero(arr1, 2) == 1);
    int arr2[3] = {-1, 3, 2};
    assert(closestToZero(arr2, 3) == -1);
    return EXIT_SUCCESS;
}