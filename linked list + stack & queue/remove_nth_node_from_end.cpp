#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* removeKthNode(ListNode* head, int k)
{
    // Step 1: Initialize two pointers
    ListNode* fast = head;
    ListNode* slow = head;

    // Step 2: Move fast k steps ahead
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    // Step 3: If fast becomes NULL, delete head
    if (fast == NULL)
        return head->next;

    // Step 4: Move both pointers until fast reaches last node
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 5: Store the node to be deleted
    ListNode* delNode = slow->next;

    // Step 6: Change links to skip the node
    slow->next = slow->next->next;

    // Step 7: Free the deleted node
    free(delNode);

    // Step 8: Return updated head
    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    head = removeKthNode(head, n);

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}