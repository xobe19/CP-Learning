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

int sum_of_all_nodes(TreeNode* root) {
    int ans = root -> data;
    for(auto x : root -> children) {
       ans += sum_of_all_nodes(x);
    }
    return ans;
}

int main() {
   auto inp = init_tree();
   cout << sum_of_all_nodes(inp);
   return 0;
}