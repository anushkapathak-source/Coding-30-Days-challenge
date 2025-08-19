#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    
    int max_from_right = arr[n-1];
    leaders.push_back(max_from_right);

    for(int i = n-2; i >= 0; i--) {
        if(arr[i] >= max_from_right) {
            leaders.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }
    
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = findLeaders(arr);
    
    cout << "Leaders: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
