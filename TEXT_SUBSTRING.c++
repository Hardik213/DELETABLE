#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: could not open input file." << endl;
        return 1;
    }

    // Read input file into string variable
    string text;
    string line;
    while (getline(inputFile, line)) {
        text += line + "\n";
    }
    inputFile.close();

    // Find and replace substring
    string findStr = "fox";
    string replaceStr = "cat";
    size_t pos = text.find(findStr);
    if (pos != string::npos) {
        text.replace(pos, findStr.length(), replaceStr);
    }

    // Open output file
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: could not open output file." << endl;
        return 1;
    }

    // Write modified text to output file
    outputFile << text;
    outputFile.close();

    return 0;
}
