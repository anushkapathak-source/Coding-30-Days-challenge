#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());  // sort the word to get key
        anagramMap[key].push_back(word);
    }

    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    vector<vector<string>> grouped = groupAnagrams(words);

    cout << "\nGrouped Anagrams:\n";
    for (auto& group : grouped) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
