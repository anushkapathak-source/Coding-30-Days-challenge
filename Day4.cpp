#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int m, int n) {
    int gap = m + n;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;

        // Compare elements in arr1
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // Compare elements in arr1 and arr2
        for (j = (gap > m) ? gap - m : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // Compare elements in arr2
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

int main() {
    int m, n;
    cout << "Enter size of arr1: ";
    cin >> m;
    cout << "Enter size of arr2: ";
    cin >> n;

    int arr1[m], arr2[n];

    cout << "Enter elements of arr1 (sorted): ";
    for (int i = 0; i < m; i++) cin >> arr1[i];

    cout << "Enter elements of arr2 (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr2[i];

    merge(arr1, arr2, m, n);

    cout << "arr1: ";
    for (int i = 0; i < m; i++) cout << arr1[i] << " ";
    cout << "\narr2: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    return 0;
}
