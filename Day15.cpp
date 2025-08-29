#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);  // stores last index of each char
    int n = s.size();
    int maxLen = 0, start = 0;       // start = window start
    
    for (int i = 0; i < n; i++) {
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1; // move start to avoid duplicate
        }
        lastIndex[s[i]] = i; // update last seen index
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;   // dynamic input from user

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " 
         << result << endl;

    return 0;
}
