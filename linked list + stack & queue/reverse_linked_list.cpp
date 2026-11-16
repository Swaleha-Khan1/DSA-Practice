#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* reverseLinkedList(Node *head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main() {

    // Creating nodes

    Node* head = new Node();

    Node* second = new Node();

    Node* third = new Node();

    // Assigning data

    head->data = 5;

    second->data = 4;

    third->data = 2;

    // Connecting nodes

    head->next = second;

    second->next = third;

    third->next = NULL;

    // Reversing linked list

    head = reverseLinkedList(head);

    // Printing linked list

    Node* temp = head;

    while (temp != NULL) {

        cout << temp->data << " ";

        temp = temp->next;

    }

    return 0;

}