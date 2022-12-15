#include "test_cases.h"

void test() {
    vector<string> words = {"GeeksforGeeks", "I", "from", "am"};
    vector<string> sorted = {"GeeksforGeeks", "from", "am", "I"};
    assert(sortStringByLength(words) == sorted);
}