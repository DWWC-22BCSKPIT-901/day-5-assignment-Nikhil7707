/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.*/

#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on value
    }
};

ListNode* mergeKLists(ListNode* lists[], int k) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (int i = 0; i < k; i++) {
        if (lists[i] != nullptr) {
            minHeap.push(lists[i]);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();

        current->next = node;
        current = current->next;

        if (node->next != nullptr) {
            minHeap.push(node->next);
        }
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Enter the number of linked lists: ";
    cin >> k;

    ListNode* lists[k];

    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter the number of elements in list " << i + 1 << ": ";
        cin >> n;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        cout << "Enter the elements in sorted order: ";
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            ListNode* newNode = new ListNode(val);

            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        lists[i] = head;
    }

    ListNode* result = mergeKLists(lists, k);
    cout << "Merged sorted list: ";
    printList(result);

    return 0;
}

