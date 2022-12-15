#include "sort_string_by_length.h"

vector<string>  sortStringByLength(vector<string> arr) {
    sort(arr.begin(), arr.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });
    return arr;
}