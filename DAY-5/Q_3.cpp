/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].*/


#include <iostream>
using namespace std;

void findStartAndEnd(int arr[], int n, int target, int& start, int& end) {
    start = -1;
    end = -1;

    int low = 0, high = n - 1;

    // Find the starting position
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            start = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;

    // Find the ending position
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            end = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

int main() {
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    int start, end;
    findStartAndEnd(arr, n, target, start, end);

    cout << "Result: [" << start << ", " << end << "]";

    return 0;
}
