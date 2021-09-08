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


pair<int, pair<int, int> > bst_subtree(BinaryTreeNode* root) {
    if(root == NULL) return {0, {INT_MAX,INT_MIN}};
    auto left = bst_subtree(root -> left);
    auto right = bst_subtree(root -> right);
    if(left.second.second < root -> data && root -> data < right.second.first)  {
        return {max(left.first,right.first) + 1, {min(root -> data, min(left.second.first, right.second.first)), max(root -> data, max(right.second.second, left.second.second))}};
    }
    else {
        return {max(left.first, right.first), {INT_MIN, INT_MAX}};
    }
}

int main() {
    auto inp = input_bt_level_wise();
    auto ans = bst_subtree(inp);
    cout << ans.first << endl;
    return 0;
}