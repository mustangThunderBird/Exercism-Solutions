#include "binary_search.h"

#include <iostream>

namespace binary_search {

    // TODO: add your solution here
    size_t find(const std::vector<int>& data, int value){
        if(data.size() <= 0){
            throw std::domain_error("You are cooked");
        }
        else if(data.size() == 1 and data.at(0) != value){
            throw std::domain_error("You are cooked");
        }
        else if(value < data.at(0) or value > data.at(data.size() - 1)){
            throw std::domain_error("You are cooked");
        }
        size_t middle = data.size() / 2;
        size_t left = 0;
        size_t right = data.size() - 1;
        while(1){
            if(data.at(middle) == value){
                return middle;
            }else {
                if(data.size() <= 1){
                    throw std::domain_error("You are cooked");
                }
                if(value > data.at(middle)){
                    left = middle + 1;
                }else if (value < data.at(middle)){
                    right = middle - 1;
                }
                if(left > right){
                    throw std::domain_error("You are cooked");
                }
                middle = left + (right - left) / 2;
            }
        }
        return 0;
    }
}  // namespace binary_search
