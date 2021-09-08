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

class BST {
private:
int minimum(BinaryTreeNode* node) {
if(node == NULL) return INT_MAX;
return min(node->data, min(minimum(node->left), minimum(node->right)));
}
BinaryTreeNode* delete_elem(int x, BinaryTreeNode* node) {
if(node == NULL) return NULL;
if(node->data == x) {
    if(node->left != NULL && node->right != NULL) {
         auto right_min = this->minimum(node->right);
          auto tmp1 = node->left;
          auto tmp2 = node->right; 
          delete node;
          auto tmp = new BinaryTreeNode(right_min);
          auto tmp_2_ryt = this -> delete_elem(right_min, node->right);
          tmp -> left = tmp1;
          tmp -> right = tmp_2_ryt;
          return tmp;
    }
    else {
        if(node -> left != NULL) {
            auto tmp = node -> left;
            delete node;
             return tmp; 
        }
        else {
            auto tmp = node -> right;
            delete node;
            return tmp;
        }
    }
}
else if (x > node->data){
node -> right = delete_elem(x, node->right);
return node;
}
else {
    node -> left = delete_elem(x,node->left);
    return node;
}
}
BinaryTreeNode* insert_elem(int x, BinaryTreeNode* node) {
if(node == NULL) return new BinaryTreeNode(x);
if(x > node -> data) {
    node -> right = insert_elem(x, node -> right);
}
else {
    node -> left = insert_elem(x, node->left);
}
return node;
}
bool hasData(int x, BinaryTreeNode* rt) {
if(rt == NULL) return false;
if(rt->data == x) return true;
if(this->hasData(x, rt->left)) return true;
if(this->hasData(x, rt->right)) return true;
return false;
}
public:
BinaryTreeNode* root;
BST(int n) {
    this->root = new BinaryTreeNode(n);
}
bool hasData(int x) {
 return this->hasData(x, root);
}
void insert(int x) {
this->root = insert_elem(x, this->root);
}
void delete_element(int x) {
this->root = delete_elem(x,this->root);
}
void print() {
queue<BinaryTreeNode*> pending;
pending.push(this->root);
while(!pending.empty()) {
auto front = pending.front();
pending.pop();
cout << front -> data << " : ";
if(front->left != NULL) {
    pending.push(front->left);
    cout << front -> left -> data<< " ";
}
cout << " , ";
if(front->right != NULL) {
    pending.push(front->right);
    cout << front -> right -> data << " ";
}
cout << endl;
}
}




};


int main() {
    BST tree(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(0);

    tree.insert(54);
    tree.insert(7);
    tree.insert(5);
    tree.insert(12);
    tree.insert(11);
    tree.insert(14);
    tree.print();
    tree.delete_element(12);
    tree.print();
    tree.delete_element(3);
    tree.print();
    return  0;
}
