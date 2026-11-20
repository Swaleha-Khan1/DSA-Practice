#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

void  reorderList(ListNode* head){
    if(head==NULL || head->next==NULL){
        return;
    }

    //find middle
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //split second half
    ListNode* second = slow->next;
    ListNode* prev = NULL;
    slow->next = NULL;

    //reverse second half.. prev represents the reversed portion and second represents what we havent reversed yet 
    while(second){
        ListNode* temp = second->next;
        second->next = prev;
        prev = second;
        second = temp;
    }

    //merge two halves
    ListNode* first = head;
    second = prev;
    while(second){
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original: ";

    printList(head);
    reorderList(head);

    cout << "Reordered: ";

    printList(head);

    return 0;
}


