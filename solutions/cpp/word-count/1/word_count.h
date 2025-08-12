#pragma once
#include <map>
#include <string>
#include <vector>
#include <sstream>

namespace word_count {

    std::vector<std::string> splitByPunctuation(const std::string& text);
    std::map<std::string, int> words(std::string s);

}  // namespace word_count
