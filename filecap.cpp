#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <output_file>" << std::endl;
        return 1;
    }

    std::string output = argv[1];

    std::string input;
    std::cout << "Enter the name of the input file: ";
    std::cin >> input;

    std::ifstream inputFile(input);

    if (!inputFile) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    std::ofstream outputFile(output);

    if (!outputFile) {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Inverse capitalization
        for (char &c : line) {
            if (std::isalpha(c)) {
                if (std::islower(c)) {
                    c = std::toupper(c);
                } else if (std::isupper(c)) {
                    c = std::tolower(c);
                }
            }
        }
        // Transfer to output file
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();

    std::cout << "Inverse capitalization complete. Check " << output << " for the result." << std::endl;

    return 0;
}
