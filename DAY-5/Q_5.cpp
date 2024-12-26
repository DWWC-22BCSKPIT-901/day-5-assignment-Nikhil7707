//Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    
    // Min-heap to store the products
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            minHeap.push((long long)nums1[i] * nums2[j]);
        }
    }

    // Extract k smallest products from the heap
    for (int i = 1; i < k; i++) {
        minHeap.pop();
    }

    return minHeap.top();
}

int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int n, m;
    cout << "Enter the size of nums1: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the size of nums2: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    int result = kthSmallestProduct(nums1, nums2, k);
    cout << "The " << k << "th smallest product is: " << result << endl;

    return 0;
}
