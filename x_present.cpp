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

bool x_present(TreeNode* root, int x) {
if(root -> data == x) return true;
for(auto y: root -> children) {
    if(x_present(y, x)) return true;
}
return false;
}

int main() {
    auto inp = input_tree_level_wise();
    int x;
    cin >> x;
    cout << x_present(inp, x);
    return 0;
}