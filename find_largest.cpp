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
TreeNode* largest = 0;
void find_largest(TreeNode* root) {
if(largest == 0 || root -> data > largest -> data) largest = root;
for(auto y : root -> children) {
    find_largest(y);
} 
}
int find_second_largest(TreeNode* root) {
find_largest(root);
auto ans1 = largest;
ans1 -> data = INT_MIN;
largest = 0;
find_largest(root);
return largest -> data;
}
int larg = INT_MIN;
int second_larg = INT_MIN;
void second_largest_better(TreeNode* root) {
if(root -> data > larg) {
second_larg = larg;
larg = root -> data;
}
else if(root -> data > second_larg && root -> data < larg) {
 second_larg = root -> data;
}
for(auto x : root -> children) {
    second_largest_better(x);
}
}
int main() {
    auto inp = input_tree_level_wise();
    second_largest_better(inp);
    cout << "largest : " << larg;
    cout << endl;
    cout << "second larg: " << second_larg;
    cout << endl;
    return 0;
}