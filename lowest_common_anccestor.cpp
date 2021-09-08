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

pair<int, pair<bool, bool> > lca(BinaryTreeNode* a, int x, int y) {
    if(a == NULL) return {NULL, {false, false}};
    auto left = lca(a->left, x, y);
    if(left.second.first && left.second.second) {
   return left;
    }
    auto right = lca(a->right, x, y);
    if(right.second.first && right.second.second) {
        return right;
    }
    if(a-> data == x) {
        return {a->data, {true, left.second.second || right.second.second}};
    }
    if(a->data ==y) {
        return {a -> data, {left.second.first || right.second.first,  true}};
    }
    return {a -> data, {left.second.first || right.second.first, left.second.second || right.second.second}};
}


int main() {
    auto inp = input_bt_level_wise();
    int x; 
    int y;
    cin >> x >> y;
    auto ans = lca(inp, x, y);
    cout << ((ans.second.first && ans.second.second) ? ans.first : -1 )<< endl;
}