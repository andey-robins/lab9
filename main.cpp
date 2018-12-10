// main.cpp
// Lab 9
// Last Updated:	12/10/2018
// Code by Andey Tuttle
// Liscensed under Apache 2.0 Liscense

// Main driver file

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    ifstream inputFile;
    inputFile.open("example.txt");
    string word;

    map<string, int> tally;

    while (inputFile >> word) {

        //taken from https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        //taken from https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
        for (auto c : word) {
            if (ispunct(c)) word.erase(word.find_first_of(c));
        }

        if (tally.count(word)) {
            tally[word]++;
        } else {
            tally.insert(pair<string, int>(word, 1));
        }
    }

    map<string, int>::iterator it;
    ofstream outputFile("output.txt");

    for (it = tally.begin(); it != tally.end(); it++) {
        //cout << it->first << ":" << it->second << endl;

        for (int i = it->second; i > 0; i--) {
            outputFile << it->first << " ";
        }
    }

    return 0;
}
