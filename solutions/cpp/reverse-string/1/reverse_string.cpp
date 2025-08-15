#include "reverse_string.h"
#include <vector>

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(std::string s){
    std::vector<char> temp;
    for(auto c : s){
        temp.push_back(c);
    }
    char* arr = new char[temp.size()];
    for(int i = temp.size() - 1; i >= 0; i--){
        arr[i] = temp[temp.size() - 1 - i];
    }
    return std::string(arr);
}

}  // namespace reverse_string
