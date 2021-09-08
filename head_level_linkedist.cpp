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
class Node {
    public:
    int data;
    Node* next;
    Node(int n) {
        this -> data = n;
        this -> next = NULL;
    }
};
Node* f() {
Node* head = NULL;
Node* tail = NULL;
while(true) {
    int n;
    cin >> n;
    if(n == -1) break;
    if(head == NULL) {
        head = new Node(n);
        tail = head;
    }
    else {
        auto tmp = new Node(n);
        tail -> next = tmp;
        tail = tail -> next;
    }
}
return head;

}


void print(Node* h) {
    while(h != NULL) {
        cout << h -> data << " ";
        h = h -> next;
    }
}

vector<Node*> head_level_ll(BinaryTreeNode* root) {
Node* curr_head = NULL;
Node* curr_tail = NULL;
vector<Node*> ans;
queue<BinaryTreeNode*> pending;
pending.push(root);
pending.push(NULL);
while(!pending.empty()) {
 auto front = pending.front();
 pending.pop();
 if(front == NULL) {
  ans.push_back(curr_head);
  curr_head = NULL;
  curr_tail = NULL;
  continue;
 }
 else {
     if(curr_head == NULL) {
         curr_head = new Node(front->data);
         curr_tail = curr_head;
     }
     else {
         auto tmp = new Node(front->data);
         curr_tail -> next = tmp;
         curr_tail = curr_tail->next;
     }
 }
 if(front->left != NULL) {
     pending.push(front->left);
 }
 if(front->right != NULL) {
     pending.push(front->right);
 }

if(pending.front() == NULL) {
    pending.push(NULL);
}

}
return ans;
}

int main() {
    auto inp = input_bt_level_wise();
    auto ans = head_level_ll(inp);
    for(auto x: ans) {
        print(x);
        cout << endl;
    }
    return 0;
}