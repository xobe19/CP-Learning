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
pair<int, int> get_level_and_parent(BinaryTreeNode* a, int x, int parent) {
if(a == NULL) return {NULL, NULL};
if(a->data == x) return {1, parent};
auto left = get_level_and_parent(a->left, x, a->data);
auto right = get_level_and_parent(a->right, x,a->data);
if(left.first != NULL) {
    return {left.first + 1, left.second};
}
else if(right.first != NULL) {
    return {right.first + 1, right.second};

}
return {NULL, NULL};
}
bool checkCousins(BinaryTreeNode* a,int p, int q) {
auto p_parent = get_level_and_parent(a, p, NULL);
auto q_parent = get_level_and_parent(a, q, NULL);
return p_parent.first == q_parent.first && p_parent.second != q_parent.second;
}

int main () {
    auto inp = input_bt_level_wise();
    int p;
    int q;
    cin >> p >> q;
    cout << checkCousins(inp, p, q);
    return 0;
}