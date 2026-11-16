// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){    //constructor for adding new nodes
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* y = new Node(arr[0], nullptr);
//     cout<< y->data;  //cout<<y will give a address
//     return 0;
// }

//array to ll:
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){    //constructor for adding new nodes
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };
// Node* convertArrToLL(vector<int>& arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* head = convertArrToLL(arr);
//     cout<<head->data;
    
//     return 0;
// }

//traversing a ll
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){    //constructor for adding new nodes
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };
// Node* convertArrToLL(vector<int>& arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* head = convertArrToLL(arr);
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
    
//     return 0;
// }

//length of ll
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     public:
//     int data;
//     Node* next;

//     public:
//     Node(int data1, Node* next1){    //constructor for adding new nodes
//         data = data1;
//         next = next1;
//     }
//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };
// Node* convertArrToLL(vector<int>& arr){
//     Node* head = new Node(arr[0]);
//     Node* mover = head;
//     for(int i=1;i<arr.size();i++){
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }
//     return head;
// }
// int lengthOfLL(Node* head){
//     int count = 0;
//     Node* temp = head;
//     while(temp != NULL){
//         temp = temp->next;
//         count++;
//     }
//     return count;
    
// }

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* head = convertArrToLL(arr);
//     cout<<lengthOfLL(head);
   
//     return 0;
// }

//searching for an element
#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){    //constructor for adding new nodes
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int checkIfPresent(Node* head, int val){
   
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
    
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head = convertArrToLL(arr);
    cout<<checkIfPresent(head, 48);
   
    return 0;
}

