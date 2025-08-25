#include <iostream>
#include <string>
#include <set>
using namespace std;

void permute(string str, int l, int r, set<string> &result) {
    if (l == r) {
        result.insert(str); // store unique permutations
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            swap(str[l], str[i]); // backtrack
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    set<string> result; // to avoid duplicate permutations
    permute(s, 0, s.length() - 1, result);

    cout << "Unique permutations are:\n";
    for (auto &perm : result) {
        cout << perm << " ";
    }
    cout << endl;

    return 0;
}
