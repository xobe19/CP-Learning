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
void replace_with_depth(TreeNode* root, int depth) {
    root -> data = depth;
    for(auto y : root->children) {
        replace_with_depth(y, depth+1);
    }
    
}
void level_order_print_tree(TreeNode* root) {
queue<TreeNode*> data;
data.push(root);

while(!data.empty()) {
    auto front = data.front();
    data.pop();
    cout << front -> data << ": ";
    for(auto x : front -> children) {
        cout << x -> data << ",";
        data.push(x);
    }
    cout << endl;
}

}

int main() {
auto inp = input_tree_level_wise();
replace_with_depth(inp,0);
level_order_print_tree(inp);
return 0;
}