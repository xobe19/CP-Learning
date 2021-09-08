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

void zigzag_print(BinaryTreeNode* root) {
auto pending = new vector<BinaryTreeNode*>;
(*pending).push_back(root);
bool rev = false;
while(!(*pending).empty()) {
    cout << endl;
    auto temp = new vector<BinaryTreeNode*>;
     if(rev) {
         for(auto it = (*pending).end()-1; it >= (*pending).begin(); it--) {
               cout << (*it) -> data << " "; 
         }
     }       
     else {
         for(auto x : *pending) {
             cout << x->data << " ";
         }
     }
     for(auto x : *pending) {
         if(x->left != NULL) temp->push_back(x->left);
         if(x->right != NULL) temp->push_back(x->right);
     }
     rev = !rev;
     delete pending;
     pending = temp;
}
delete pending;
}

int  main() {
    auto inp = input_bt_level_wise();
    zigzag_print(inp);
    return 0;
}