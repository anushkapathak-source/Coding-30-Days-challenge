#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {  // check if prefix matches at beginning
            prefix = prefix.substr(0, prefix.size() - 1); // shrink prefix
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    if (result.empty())
        cout << "No common prefix found." << endl;
    else
        cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
