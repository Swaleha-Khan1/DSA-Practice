#include<bits/stdc++.h>
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

Node* mergeKLists(vector<Node*>& listArray){     //receives a vector containing the heads of all K LL
    priority_queue<
    pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>
    > pq;

    //insert the first node of every list
    for(int i=0; i < listArray.size(); i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }

    //dummy node
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    //process min heap
    while(!pq.empty()){
        auto it = pq.top();  //same as: pair<int, Node*> it;
        pq.pop();

        //insert the next node of the same list
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }

        //attach the smallest node to result
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
} 

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
Node* createLL(vector<int> arr){
    if(arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=0; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<Node*> listArray;

    listArray.push_back(createLL({4,6,8}));
    listArray.push_back(createLL({2,5,7}));
    listArray.push_back(createLL({1,3,9}));

    Node* ans = mergeKLists(listArray);
    
    cout<<"Merged linked list: ";
    printList(ans);

    return 0;
}