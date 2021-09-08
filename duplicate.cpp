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

BinaryTreeNode* duplicate(BinaryTreeNode* root) {
    if(root == NULL) return NULL;
    auto new_root = new BinaryTreeNode(root->data);
    new_root -> left = duplicate(root->left);
    new_root -> right = duplicate(root->right);
   return new_root;
}

BinaryTreeNode* special_dup(BinaryTreeNode* root) {
if(root == NULL) return NULL;
root -> right = special_dup(root -> right);
auto left_bkup = root -> left;
root -> left = new BinaryTreeNode(root  -> data);
root -> left -> left = special_dup(left_bkup);
return root;
}

int main() {
    auto inp = input_bt_level_wise();
    auto ans = special_dup(inp);
    print_level_wise_bt(ans);
    return 0;
}