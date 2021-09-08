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
void print_bst(BinaryTreeNode* root, int k) {
vector<BinaryTreeNode*> data = {root};
while(k--) {
    vector<BinaryTreeNode*> backup = data;
    data.clear();
    for(auto x : backup) {
        if(x -> left != NULL) data.push_back(x -> left);
        if(x -> right != NULL) data.push_back(x -> right);
    }

}
for(auto x : data) {
    cout << x -> data << " ";
}
}

int dist(BinaryTreeNode* root, int x) {
if(root == NULL) return -1;
if(root -> data == x) return 0;
auto left = dist(root->left, x);
auto right = dist(root -> right, x);
if(left != -1) return left + 1;
if(right != -1) return right + 1;
return -1;
}
void print_dist_k(BinaryTreeNode* root, int x,int k) {
    if(root == NULL) return;
    if(root -> data == x) {
        print_bst(root, k);
        return;
    }
auto left = dist(root -> left, x) + 1;
auto right = dist(root -> right, x) + 1;
if(left != 0) {
if(k >= left+1) {
print_bst(root->right, k - left - 1);
}
if(k == 1 && left == 1) {
    cout << root -> data << " "; 
}
print_dist_k(root -> left, x, k);
}
else if(right != 0){
   if(k >= right+1) {
       print_bst(root->left, k -  right - 1);
   } 
   if(k == 1 && right == 1) {
       cout << root -> data << " ";
   }
   print_dist_k(root -> right, x, k);
}
}


int main() {
    auto inp = input_bt_level_wise();
    int x;
    int k;
    cin >> x >> k;
    print_dist_k(inp, x, k);
    return 0;
}