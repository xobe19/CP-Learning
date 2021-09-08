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

int max_sum = 0;
int node_with_max_sum = 0;
void node_with_max_child_sum(TreeNode* root) {
int sum = 0;
for(auto x : root -> children) {
    sum += x -> data;
}
if(sum > max_sum) {
    max_sum = sum;
    node_with_max_sum = root -> data;
}

for(auto x : root -> children) {
node_with_max_child_sum(x);
}

}


int main() {
auto inp = input_tree_level_wise();
node_with_max_child_sum(inp);
cout << max_sum << endl;
cout << node_with_max_sum << endl;
return 0;
}