#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    // Check if the correct number of arguments is provided
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];  // Input file name
    std::string s1 = argv[2];        // String to find
    std::string s2 = argv[3];        // String to replace with

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
        size_t pos = 0;  // Position to start searching from
        // Find and replace all occurrences of s1 with s2 in the current line
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);  // Replace s1 with s2
            pos += s2.length();  // Move position past the replacement to avoid infinite loop
        }
        // Write the modified line to output file
        outfile << line;
    }
    infile.close();
    outfile.close();
    std::cout << "File processed successfully. Output written to: " << outfilename << std::endl;
    return 0;
}
