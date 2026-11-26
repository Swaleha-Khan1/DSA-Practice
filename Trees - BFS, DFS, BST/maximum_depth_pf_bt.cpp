#include <iostream>
#include <queue>
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
int maxDepth(TreeNode* root){
    if(root==NULL) return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return 1 + max(l, r);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(1);

    cout<<maxDepth(root);

    return 0;
}