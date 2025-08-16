#include <iostream>
#include <vector>
using namespace std;

// Function to find missing number
int findMissingNumber(vector<int>& arr, int n) {
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        arrSum += arr[i];
    }
    return totalSum - arrSum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n - 1 << " elements from 1 to " << n << " (with one missing):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr, n);

    cout << "Missing number: " << missing << endl;

    return 0;
}
