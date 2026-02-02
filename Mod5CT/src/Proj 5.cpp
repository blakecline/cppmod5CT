#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string getUserInput() {
    cout << "Enter text to append to CSC450_CT5_mod5.txt\n";
    cout << "Type END on its own line to finish:\n\n";

    string input;
    string line;

    while (true) {
        getline(cin, line);

        if (line == "END") {
            break;
        }

        input += line + "\n";
    }

    return input;
}

int main() {
    const string inputFile = "CSC450_CT5_mod5.txt";
    const string reverseFile = "CSC450-mod5-reverse.txt";


    string userText = getUserInput();


    ofstream outFile(inputFile, ios::app);
    if (!outFile) {
        cerr << "Error opening file for appending.\n";
        return 1;
    }

    outFile << "\n--- Appended User Input ---\n";
    outFile << userText;
    outFile.close();

    cout << "\nData successfully appended.\n";


    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return 1;
    }

    string fileContents(
        (istreambuf_iterator<char>(inFile)),
        istreambuf_iterator<char>()
    );
    inFile.close();


    reverse(fileContents.begin(), fileContents.end());


    ofstream reverseOut(reverseFile);
    if (!reverseOut) {
        cerr << "Error creating reversed file.\n";
        return 1;
    }

    reverseOut << fileContents;
    reverseOut.close();

    cout << "Reversed file created: " << reverseFile << endl;
    cout << "Program completed successfully.\n";

    return 0;
}
