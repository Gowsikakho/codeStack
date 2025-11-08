#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute maximum subarray sum using Kadane's Algorithm
pair<int, pair<int,int>> kadane_subarray(const vector<int>& arr) {
    int max_sum = arr[0], current_sum = arr[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (current_sum + arr[i] < arr[i]) {
            current_sum = arr[i];
            temp_start = i;
        } else {
            current_sum += arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    return {max_sum, {start, end}}; // Return sum and start-end indices
}

// Function to generate all subarrays of a vector
vector<vector<int>> generate_subarrays(const vector<int>& arr) {
    vector<vector<int>> subarrays;
    int n = arr.size();

    for (int i = 0; i < n; i++) {          // Start index
        for (int j = i; j < n; j++) {      // End index
            vector<int> subarr(arr.begin() + i, arr.begin() + j + 1);
            subarrays.push_back(subarr);
        }
    }

    return subarrays;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Kadane's Algorithm
    auto result = kadane_subarray(arr);
    int max_sum = result.first;
    int start = result.second.first;
    int end = result.second.second;

    cout << "Maximum Subarray Sum = " << max_sum << endl;
    cout << "Maximum Subarray: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // Generate all subarrays
    cout << "All Subarrays:\n";
    vector<vector<int>> subarrays = generate_subarrays(arr);
    for (auto& subarr : subarrays) {
        cout << "[ ";
        for (int x : subarr) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
