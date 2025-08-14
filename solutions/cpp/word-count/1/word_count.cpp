#include "word_count.h"
#include <iostream>
#include <algorithm>
#include <cctype>

namespace word_count {
    std::vector<std::string> splitByPunctuation(const std::string& text) {
        std::vector<std::string> tokens;
        std::string currentToken;
    
        auto stripApostrophes = [](const std::string& word) {
            size_t start = 0;
            size_t end = word.size();
    
            // Remove leading apostrophes
            while (start < end && word[start] == '\'') {
                start++;
            }
    
            // Remove trailing apostrophes
            while (end > start && word[end - 1] == '\'') {
                end--;
            }
    
            return word.substr(start, end - start);
        };
    
        for (char c : text) {
            if (std::isspace(c) || (std::ispunct(c) && c != '\'')) {
                if (!currentToken.empty()) {
                    std::string cleaned = stripApostrophes(currentToken);
                    if (!cleaned.empty()) {
                        tokens.push_back(cleaned);
                    }
                    currentToken.clear();
                }
            } else {
                currentToken += c;
            }
        }
    
        // Handle last token
        if (!currentToken.empty()) {
            std::string cleaned = stripApostrophes(currentToken);
            if (!cleaned.empty()) {
                tokens.push_back(cleaned);
            }
        }
    
        return tokens;
    }
        
    std::map<std::string, int> words(std::string s)
    {
        // std::cout << s;
        std::map<std::string, int> word_map;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::vector<std::string> v = splitByPunctuation(s);
        for(auto w : v){
            std::cout << w << "\n";
            if(word_map.count(w) > 0){
                word_map[w] += 1;
            }else{
                word_map[w] = 1;
            }
        }
        return word_map;
    }

}  // namespace word_count
