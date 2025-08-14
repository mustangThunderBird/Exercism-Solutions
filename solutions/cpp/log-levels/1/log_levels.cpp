#include <string>

namespace log_line {
std::string message(std::string line) {
    int idx = line.find(":") + 2;
    std::string ll = line.substr(idx);
    return ll;
}

std::string log_level(std::string line) {
    int idx = line.find("]");
    std::string lvl = "";
    for(int i = 1; i < idx; ++i){
        lvl += line[i];
    }
    return lvl;
}

std::string reformat(std::string line) {
    std::string content = message(line);
    std::string level = log_level(line);
    std::string rfrmt = content + " (" + level + ")";
    return rfrmt;
}
}  // namespace log_line
