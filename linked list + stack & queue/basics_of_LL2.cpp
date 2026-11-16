//delete head
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
// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// Node* removeHead(Node* head){
//     if(head==NULL) return head;
//     Node* temp = head;
//     head = head->next;
//     delete temp;
//     return head;
// }

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* head = convertArrToLL(arr);
//     head = removeHead(head);
//     print(head);
//     return 0;
// }


//delete last(tail)
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
// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// Node* removeTail(Node* head){
//     if(head==NULL) return NULL;   //for no element

//     if(head->next == NULL){     //for one element
//         delete head;
//         return NULL;
//     }
//     Node* temp = head;
//     while(temp->next->next != NULL){     //for two or more... stopping at second last
//         temp  = temp->next;
//     }
//     delete temp->next;
//     temp->next = nullptr;

//     return head;
// }

// int main(){
//     vector<int> arr={1,2,3,4,5};
//     Node* head = convertArrToLL(arr);
//     head = removeTail(head);
//     print(head);
//     return 0;
// }


//deleting kth element
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
// void print(Node* head){
//     while(head!=NULL){
//         cout<<head->data<<" ";
//         head=head->next;
//     }
//     cout<<endl;
// }
// Node* deleteK(Node* head, int k)
// {
//     if (head == NULL)
//         return head;

//     if (k == 1)
//     {
//         Node* temp = head;
//         head = head->next;
//         free(temp);
//         return head;
//     }

//     int cnt = 0;
//     Node* temp = head;
//     Node* prev = NULL;

//     while (temp != NULL)
//     {
//         cnt++;

//         if (cnt == k)
//         {
//             prev->next = prev->next->next;
//             free(temp);
//             break;
//         }

//         prev = temp;
//         temp = temp->next;
//     }

//     return head;
// }
// int main(){
//     vector<int> arr={10,9,60,33,21};
//     Node* head = convertArrToLL(arr);
//     head = deleteK(head, 2);
//     print(head);
//     return 0;
// }

//delete kth element
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
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* deleteel(Node* head, int el)
{
    if (head == NULL)
        return head;

    if (head->data == el)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL)
    {

        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
int main(){
    vector<int> arr={10,9,60,33,21};
    Node* head = convertArrToLL(arr);
    head = deleteel(head, 33);
    print(head);
    return 0;
}