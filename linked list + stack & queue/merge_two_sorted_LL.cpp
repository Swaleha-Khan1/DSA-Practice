#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* mergeTwoLists(Node* head1, Node* head2) {

    Node* t1 = head1;
    Node* t2 = head2;

    Node* dNode = new Node(-1);
    Node* temp = dNode;

    while (t1 != NULL && t2 != NULL) {

        if (t1->data < t2->data) {

            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else {

            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if (t1) {
        temp->next = t1;
    }
    else {
        temp->next = t2;
    }

    Node* head = dNode->next;
    delete dNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {

    // First sorted linked list: 1 -> 3 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);

    // Second sorted linked list: 2 -> 4 -> 6
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    Node* head = mergeTwoLists(head1, head2);

    cout << "Merged Linked List: ";
    printList(head);

    return 0;
}