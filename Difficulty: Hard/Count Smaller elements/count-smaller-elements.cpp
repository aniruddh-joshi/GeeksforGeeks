//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    void merge(vector<pair<int, int>> &arr, vector<int> &count, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<pair<int, int>> L(n1);
    vector<pair<int, int>> R(n2);
    
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left, right_count = 0;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            count[L[i].second] += right_count;
            ++i;
        } else {
            arr[k] = R[j];
            ++right_count;
            ++j;
        }
        ++k;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        count[L[i].second] += right_count;
        ++i;
        ++k;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<pair<int, int>> &arr, vector<int> &count, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
}
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n = arr.size();
    vector<pair<int, int>> arr_with_indices(n);
    vector<int> count(n, 0);
    
    for (int i = 0; i < n; ++i) {
        arr_with_indices[i] = {arr[i], i};
    }
    
    mergeSort(arr_with_indices, count, 0, n - 1);
    
    return count;
    }

};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends