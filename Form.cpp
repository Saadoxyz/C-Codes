#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outfile("data.txt");
    outfile << "Hello,\n"
            << "I hope you are doing very well.\n"
            << "I just wanted to say you Best of the luck.\n";
    outfile.close();

    ifstream infile("data.txt");
    string word;

    while (infile >> word) {
        wordCounts[word]++;
    }
    infile.close();
    string targetWord;
    cout << "Enter the word you want to find occurrence: ";
    cin >> targetWord;
    cout << "Occurrence of word [" << targetWord << "] = " << wordCounts[targetWord] << endl;

    return 0;
}