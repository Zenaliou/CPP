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

    // Open the input file for reading
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open input file '" << filename << "'." << std::endl;
        return (1);
    }

    // Create output file name by appending ".replace" to original filename
    std::string outfilename = filename + ".replace";
    
    // Open the output file for writing
    std::ofstream outfile(outfilename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: cannot create output file '" << outfilename << "'." << std::endl;
        infile.close();
        return (1);
    }

    std::string line;
    bool first_line = true;  // Flag to handle newlines properly
    while (std::getline(infile, line))
    {
        // Add newline before each line except the first one
        if (!first_line)
            outfile << std::endl;
        first_line = false;
        
        std::string result;
        size_t pos = 0;  // Position to start searching from
        size_t found;
        
        // Find and replace all occurrences of s1 with s2 in the current line
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            // Add the part before the found string
            result += line.substr(pos, found - pos);
            // Add the replacement string
            result += s2;
            // Move position past the found string
            pos = found + s1.length();
        }
        // Add the remaining part of the line
        result += line.substr(pos);
        
        // Write the modified line to output file
        outfile << result;
    }
    
    infile.close();
    outfile.close();
    std::cout << "File processed successfully. Output written to: " << outfilename << std::endl;
    return 0;
}
