#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> generteAnagram(string word) {
    vector <string> anagrams;
    sort(word.begin(), word.end());
    anagrams.push_back(word);
    while(next_permutation(word.begin(), word.end()))
        anagrams.push_back(word);
    return anagrams;
}

