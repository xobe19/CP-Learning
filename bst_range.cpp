#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
    public:
int data;
BinaryTreeNode* left = NULL;
BinaryTreeNode* right = NULL;
BinaryTreeNode(int i) {
this-> data = i;
}

};
void print_level_wise_bt(BinaryTreeNode* root) {
queue<BinaryTreeNode*> pending;
pending.push(root);

while(!pending.empty()) {
    auto front = pending.front();
    pending.pop();
    cout << front-> data << " : ";
    if(front -> left != NULL) {
        cout << front -> left -> data<< "  ";
        pending.push(front-> left);
    }
    cout << ",";
    if(front->right != NULL) {
        cout << front -> right -> data<< " ";
        pending.push(front-> right);
    }
    cout << endl;
}



}
BinaryTreeNode* input_bt_level_wise(){
    int t;
    cin >> t;
    if(t == -1) return NULL;
    auto root = new BinaryTreeNode(t);
    queue<BinaryTreeNode*> pending;
    pending.push(root);
    while(!pending.empty()) {
       auto front = pending.front();
       pending.pop();
       int l;
       cin >> l;
       if(l != -1) {
           auto l_node = new BinaryTreeNode(l);
           pending.push(l_node);
           front->left = l_node;
       } 
       int r;
       cin >> r;
       if(r != -1) {
           auto r_node = new BinaryTreeNode(r);
           pending.push(r_node);
           front->right = r_node;
       }
    } 
    return root;
}

void print_bst_range(BinaryTreeNode* root, int lo, int hi) {
    if(root == NULL) return;
    if(root -> data >= lo && root -> data <= hi) {
        cout << root -> data << " ";
        print_bst_range(root->left, lo, hi);
        print_bst_range(root->right, lo, hi);
    }
    else if(root -> data >= hi) {
        print_bst_range(root->left, lo, hi);
    }
    else if(root -> data <= lo) {
        print_bst_range(root->right, lo, hi);
    }
}

int main() {
    auto inp = input_bt_level_wise();
    int lo;
    int hi;
    cin >> lo >> hi;
    print_bst_range(inp, lo, hi);
    return 0;
}