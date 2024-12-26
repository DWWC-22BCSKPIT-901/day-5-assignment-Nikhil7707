//Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

#include <iostream>
using namespace std;

bool isPresent(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) return true;
        else if (arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    int n = 5;
    int arr[] = {1, 3, 5, 7, 9};
    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    if (isPresent(arr, n, k)) cout << "True";
    else cout << "False";

    return 0;
}
