#include "anagram.h"
#include <cassert>

int main() {
    vector<string> v1 = {""};
    sort(v1.begin(), v1.end());
    assert(generteAnagram("") == v1);

    vector<string> v2 ={"b"};
    sort(v2.begin(), v2.end());
    assert(generteAnagram("b") == v2);

    vector<string> v3 = {"biro", "bior", "brio", "broi", "boir", "bori", "ibro", "ibor", "irbo", "irob", "iobr", "iorb", "rbio", "rboi", "ribo", "riob", "roib", "robi", "obir", "obri", "oibr", "oirb", "orbi", "orib"};
    sort(v3.begin(), v3.end());
    assert(generteAnagram("biro") == v3);

    return 0;
}