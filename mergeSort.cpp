#include <bits/stdc++.h>
using namespace std;

// Merge function to combine two sorted halves
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Merge back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Utility function for reuse
void mergeSort(vector<int>& arr) {
    if (!arr.empty()) {
        mergeSort(arr, 0, arr.size() - 1);
    }
}

// Example usage
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
