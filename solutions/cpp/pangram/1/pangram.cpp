#include "pangram.h"
#include <iostream>
#include <map>
#include <cctype>
#include <algorithm>

namespace pangram {

// TODO: add your solution here
bool is_pangram(std::string s){
    std::map<char, int> seen = {
        {'a',0},
        {'b',0},
        {'c',0},
        {'d',0},
        {'e',0},
        {'f',0},
        {'g',0},
        {'h',0},
        {'i',0},
        {'j',0},
        {'k',0},
        {'l',0},
        {'m',0},
        {'n',0},
        {'o',0},
        {'p',0},
        {'q',0},
        {'r',0},
        {'s',0},
        {'t',0},
        {'u',0},
        {'v',0},
        {'w',0},
        {'x',0},
        {'y',0},
        {'z',0}
    };
    std::transform(s.begin(), s.end(), s.begin(),[](unsigned char c){return std::tolower(c); });
    const char* cs = s.c_str();
    int i = 0;
    while(*(cs + i) != '\0'){
        seen[*(cs + i)] += 1;
        i++;
    }
    for(auto count : seen){
        
        if(count.second < 1){
            return false;
        }
    }
    return true;
}

}  // namespace pangram
