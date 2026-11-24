#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* reverseLinkedList(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node* getKthNode(Node* temp, int k){
    for(int i=1; i < k && temp != NULL; i++){    //start i from 1 because temp is pointing at first node and we need to reach the third 
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k){
    Node* temp = head;
    Node* prevlast = NULL;

    while(temp != NULL){
        Node* KthNode = getKthNode(temp, k);

        //k nodes not found
        if(KthNode == NULL){
            if(prevlast) prevlast->next = temp; //connects the previuosly reversed group to the ramaining nodes
            break;
        }

        Node* nextNode = KthNode->next;
        KthNode->next = NULL;

        reverseLinkedList(temp);

        //reversing first list
        if(temp == head){
            head = KthNode;
        }
        else{
            prevlast->next = KthNode;
        }
        prevlast = temp;
        temp = nextNode;
    }
    return head;
}

void printList(Node* head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);

    head->next->next = new Node(3);

    head->next->next->next = new Node(4);

    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = new Node(6);

    head->next->next->next->next->next->next = new Node(7);

    int k = 3;

    cout << "Original Linked List: ";

    printList(head);

    head = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";

    printList(head);

    return 0;

}