//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

#include <iostream>
#include <algorithm>
using namespace std;

void sortedSquares(int arr[], int n) {
    int result[n];
    int left = 0, right = n - 1, index = n - 1;

    while (left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    cout << "Sorted squares: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortedSquares(arr, n);

    return 0;
}
