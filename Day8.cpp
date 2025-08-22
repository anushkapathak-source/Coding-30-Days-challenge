#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Split by spaces
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse order
    string result = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) result += " ";
    }

    return result;
}

int main() {
    string input = "  the   sky  is blue  ";
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: \"" << reverseWords(input) << "\"" << endl;
    return 0;
}
