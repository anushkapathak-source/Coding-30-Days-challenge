#include <iostream>
#include <vector>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int trappedWater = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                trappedWater += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                trappedWater += rightMax - height[right];
            right--;
        }
    }
    return trappedWater;
}

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = trapRainWater(height);
    cout << "Total trapped rain water: " << result << endl;

    return 0;
}
