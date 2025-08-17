#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    // Phase 1: Detect the cycle using Tortoise & Hare
    int slow = arr[0];      // slow starts at first element
    int fast = arr[0];      // fast also starts at first element

    do {
        slow = arr[slow];        // move slow by 1 step
        fast = arr[arr[fast]];   // move fast by 2 steps
    } while (slow != fast);      // keep going until they meet

    // Phase 2: Find the entrance of the cycle (duplicate number)
    slow = arr[0];           // reset slow to start
    while (slow != fast) {   // move both one step at a time
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;  // when they meet again, it's the duplicate number
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}
