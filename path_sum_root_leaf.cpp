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

void path_sum_root_leaf(BinaryTreeNode* root, int k, vector<int> path_already_taken) {
if(k==0) {
    if(root != NULL) return;
    for(auto x: path_already_taken) {
        cout << x << " ";
    }
    cout<<endl;
}
else {

    if(root == NULL) return;
path_already_taken.push_back(root->data);
if(k - root -> data == 0) {
    path_sum_root_leaf(root -> left == NULL ? root -> right : root -> left, k - root -> data, path_already_taken);
    return;
}
path_sum_root_leaf(root->left, k - root -> data, path_already_taken);
path_sum_root_leaf(root->right, k- root->data, path_already_taken);
}

}

int main() {
    auto inp = input_bt_level_wise();
    int k; cin >> k;
    vector<int> path_al;
    path_sum_root_leaf(inp, k, path_al);
    return 0;
}