#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

//functions!!
// 1. capitalize option
string capitalize(const string &str) {
    string r = str;
    transform(r.begin(), r.end(), r.begin(), ::toupper);
    return r;
}

// 2. lowercase option 
string lowercase(const string &str) {
     string r = str;
    transform(r.begin(), r.end(), r.begin(), ::tolower);
    return r;
}

// 3. remove punctuation and numbers option
string remove(const string &str) {
    string r = str;
    r.erase(remove_if(r.begin(), r.end(), ::ispunct), r.end());
    r.erase(remove_if(r.begin(), r.end(), ::isdigit), r.end());
    return r;
}

// main
int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error: Unable to open input or output file." << endl;
        return 1;
    }

    string line;
    int option;

    while (getline(input, line)) {
        cout << "Please select an option for the following line:" << endl;
        cout << "1. Capitalize" << endl;
        cout << "2. Lowercase" << endl;
        cout << "3. Remove punctuation and numbers" << endl;
        cout << "Please enter option: ";

        cin >> option;

        string r;

        switch (option) {
            case 1:
                r = capitalize(line);
                break;
            case 2:
                r = lowercase(line);
                break;
            case 3:
                r = remove(line);
                break;
            default:
                cerr << "Invalid option. Skipping this line." << endl;
                continue;  
        }

        output << r << endl;
    }

    input.close();
    output.close();

    cout << "Output written to 'output.txt'." << endl;

    return 0;
}
