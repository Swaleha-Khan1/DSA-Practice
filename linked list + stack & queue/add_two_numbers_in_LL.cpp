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

Node* addTwoNumbers(Node* num1, Node* num2) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL ){
        int sum = 0;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummy->next;
}
    void printList(Node* head) {

    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // First number: 2 -> 4 -> 3
    Node* num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(3);

    // Second number: 5 -> 6 -> 4
    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(4);

    Node* result = addTwoNumbers(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}