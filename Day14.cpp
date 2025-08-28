#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most K distinct characters
int atMostK(string s, int k) {
    int n = s.size();
    int left = 0, right = 0, count = 0;
    unordered_map<char, int> freq;

    while (right < n) {
        freq[s[right]]++;

        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    return count;
}

// Function to count substrings with exactly K distinct characters
int exactlyK(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter value of k: ";
    cin >> k;

    cout << "Number of substrings with exactly " << k << " distinct characters = "
         << exactlyK(s, k) << endl;

    return 0;
}
