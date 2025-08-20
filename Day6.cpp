#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubarraysWithZeroSum(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixSumMap;
    vector<pair<int, int>> result;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Case 1: subarray from 0 to i
        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        // Case 2: subarray between previous same prefix sums
        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            for (auto startIndex : prefixSumMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store this index in prefix sum map
        prefixSumMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> result = findSubarraysWithZeroSum(arr);

    cout << "Subarrays with zero sum (start_index, end_index):\n";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
