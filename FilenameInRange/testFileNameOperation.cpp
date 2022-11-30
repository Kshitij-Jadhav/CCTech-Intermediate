#include "FileNameOperation.h"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    FileNameOperation ob;
    assert(ob.getFilenameRange("hiker").first == 0 && ob.getFilenameRange("hiker").second == 5);
    assert(ob.getFilenameRange("fizz.Buzz").first == 0 && ob.getFilenameRange("fizz.Buzz").second == 9);
    assert(ob.getFilenameRange("fizzBuzz_test.d").first == 0 && ob.getFilenameRange("fizzBuzz_test.d").second == 8);
    assert(ob.getFilenameRange("hiker.feature").first == 0 && ob.getFilenameRange("hiker.feature").second == 5);
    assert(ob.getFilenameRange("test.hiker.feature").first == 5 && ob.getFilenameRange("test.hiker.feature").second == 10);
    assert(ob.getFilenameRange("hiker.test.feature").first == 0 && ob.getFilenameRange("hiker.test.feature").second == 5);
    
}