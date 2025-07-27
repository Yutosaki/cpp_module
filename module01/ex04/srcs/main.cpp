#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << infile.rdbuf();
    std::string fileContent = buffer.str();

    infile.close();
    
    std::string replacedContent = replace(fileContent, s1, s2);

    std::ofstream outfile(filename + ".replace");
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create output file." << std::endl;
        return 1;
    }

    outfile << replacedContent;

    outfile.close();

    std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;

    return 0;
}