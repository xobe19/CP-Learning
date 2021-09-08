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


BinaryTreeNode* construct_from_pre_in(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end)  {
    if(pre_begin > pre_end) return NULL;
if(pre_begin  == pre_end) return new BinaryTreeNode(*pre_begin);
auto root = new BinaryTreeNode(*pre_begin);
auto left_pre_begin = pre_begin + 1;
auto left_in_begin = in_begin;
vector<int>::iterator root_iter;
for(auto it = in_begin; it <= in_end; it++) {
    if(root->data == *it) {
      root_iter = it;
      break;
    }
}
auto left_in_end = root_iter-1;
int left_len =  left_in_end - left_in_begin;
auto left_pre_end = left_pre_begin + left_len;
auto right_in_begin = root_iter+1;
auto right_in_end = in_end;
auto right_pre_end = pre_end;
int right_len = right_in_end-right_in_begin;
auto right_pre_begin = right_pre_end - right_len;
root->left = construct_from_pre_in(left_pre_begin, left_pre_end, left_in_begin, left_in_end);
root->right = construct_from_pre_in(right_pre_begin, right_pre_end, right_in_begin, right_in_end);
return root;
}


int  main() {
    vector<int> inOrder;
    vector<int> preOrder;
int n;
cin >> n;
while(n--) {
    int t;
    cin >> t;
    inOrder.push_back(t);

}
int m;
cin >> m;
while(m--) {
    int t;
    cin >> t;
    preOrder.push_back(t);
}
auto ans = construct_from_pre_in(preOrder.begin(), preOrder.end()-1, inOrder.begin(), inOrder.end()-1);
print_level_wise_bt(ans);
return 0;
}