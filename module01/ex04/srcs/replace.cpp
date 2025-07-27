#include "replace.hpp"

std::string replace(const std::string &content, const std::string &s1, const std::string &s2) {
    std::string result;
    std::size_t start_pos = 0;
    std::size_t found_pos = 0;

    while ((found_pos = content.find(s1, start_pos)) != std::string::npos) {
        result.append(content, start_pos, found_pos - start_pos);
        result.append(s2);
        start_pos = found_pos + s1.length();
    }
    result.append(content, start_pos, content.length() - start_pos);

    return result;
}