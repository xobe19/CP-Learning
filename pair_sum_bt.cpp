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

void pair_sum(vector<int> &a, int x) {
auto it1 = a.begin();
auto it2 = a.end() - 1;
while(it1 < it2) {
    if(*it1 + *it2 > x) {
        it2--;
    }
    else if(*it1 + *it2 < x) {
        it1++;
    }
    else {
        cout << *it1 << " " << *it2 << endl;
        it1++;
        it2--;
    }
}

}

void in_order_vector(BinaryTreeNode* a, vector<int>& tmp) {
if(a == NULL) return;
in_order_vector(a->left, tmp);
tmp.push_back(a->data);
in_order_vector(a->right, tmp);
}

void pair_sum_bt(BinaryTreeNode* a, int x) {
    vector<int> in_order;
    in_order_vector(a, in_order);
    pair_sum(in_order, x);
}

int main() {
    auto inp = input_bt_level_wise();
    int x; cin >> x;
    pair_sum_bt(inp, x);
}