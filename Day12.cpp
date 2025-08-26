#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mp = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // If it's a closing bracket
        if (mp.find(c) != mp.end()) {
            if (!st.empty() && st.top() == mp[c]) {
                st.pop(); // matched
            } else {
                return false; // mismatch
            }
        } 
        else {
            // If it's an opening bracket
            st.push(c);
        }
    }

    return st.empty(); // valid if nothing left unmatched
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
