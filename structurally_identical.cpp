#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
int data;
vector< TreeNode*> children;
TreeNode(int n){
    this -> data = n;
}
};

TreeNode* one = new TreeNode(1);
TreeNode* two = new TreeNode(2);
TreeNode* three = new TreeNode(3);
TreeNode* four = new TreeNode(4);
TreeNode* five = new TreeNode(5);
TreeNode* six = new TreeNode(6);

TreeNode* init_tree() {
one -> children.push_back(two);
one -> children.push_back(three);
one -> children.push_back(four);
two -> children.push_back(five);
two -> children.push_back(six);
return one;
}

TreeNode* input_tree_level_wise() {
  int n;
  cin >> n;
  auto root = new TreeNode(n);
  queue<TreeNode*> data;
  data.push(root);
  while(!data.empty()) {
   auto front = data.front();
   data.pop();
   int num_of_child;
   cin >> num_of_child;
   while(num_of_child--) {
       int t;
       cin >> t;
       TreeNode* tmp = new TreeNode(t);
       data.push(tmp);
       front->children.push_back(tmp);
   } 
  }
  return root;
}

bool structurally_identail(TreeNode* root1, TreeNode* root2) {
    if(root1 -> data != root2 -> data) return false;
    if((root1 -> children).size() != (root2 -> children).size()) return false;
    for(int i = 0; i < (root1 -> children).size(); i++) {
       if(structurally_identail((root1 -> children)[i], (root2 -> children)[i]) == false) return false;
    }
    return true;
}

int main() {
    auto inp = input_tree_level_wise();
    auto inp2 = input_tree_level_wise();
    cout << structurally_identail(inp, inp2);
    return 0;
}