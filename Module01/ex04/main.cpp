#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return (1);
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open input file '" << filename << "'." << std::endl;
        return (1);
    }

    std::string outfilename = filename + ".replace";
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: cannot create output file '" << outfilename << "'." << std::endl;
        infile.close();
        return (1);
    }

    std::string line;
    bool first_line = true;
    
    while (std::getline(infile, line))
    {
        if (!first_line)
            outfile << std::endl;
        first_line = false;
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        outfile << line;
    }
    infile.close();
    outfile.close();
    std::cout << "File processed successfully. Output written to: " << outfilename << std::endl;
    return 0;
}
