#include <iostream>

std::string toUpper(const std::string& str) {
    std::string result;

    for (size_t i = 0; i < str.length(); i++)
        result += std::toupper(str[i]);
    return result;
}

int main(int argc, char **argv)
{
    std::string upper;

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        upper += (std::string)toUpper(argv[i]);
        if (i != argc - 1)
            upper += " ";
    }
    std::cout << upper << std::endl;
    return 0;
}
