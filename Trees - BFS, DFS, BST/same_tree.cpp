#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool sameTree(TreeNode* p, TreeNode* q){

    //when either pointer is null we need to check whether both pointers are null
    if(p==NULL || q==NULL){
        return (p==q);
    }

    return (p->val == q->val) && sameTree(p->left, q->left) && sameTree(p->right, q->right);
}

int main() {
    TreeNode* p = new TreeNode(4);
    p->left = new TreeNode(2);
    p->right = new TreeNode(7);
    p->left->left = new TreeNode(1);

    TreeNode* q = new TreeNode(4);
    q->left = new TreeNode(2);
    q->right = new TreeNode(7);
    q->left->left = new TreeNode(1);

    if(sameTree(p, q)){
        cout<<"Both Trees ar Identical";
    }
    else{
        cout<<"Trees are not Identical";
    }

    return 0;
}