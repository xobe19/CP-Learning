#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<int**, int> input_graph() {
int v;
int e;
cin >> v >> e;
int** adjacency_matrix = new int*[v];
for(int i = 0; i < v; i++) {
    int* curr = new int[v];
    for(int j = 0; j < v; j++) {
        curr[j] = 0;
    }
    adjacency_matrix[i] = curr;
}
while(e--) {
    int a; int b;
    cin >> a >> b;
    adjacency_matrix[a][b] = 1;
    adjacency_matrix[b][a] = 1;
}
return {adjacency_matrix, v};
}

pair<bool, bool> has_path_bfs(int** adj_matrix,int v, int start, int a, int b, unordered_map<int, bool> &pushed_to_queue) {
pair<bool, bool> ans = {false, false};
queue<int> pending;

pending.push(start);
pushed_to_queue.insert({start, true});
while(!pending.empty()) {
auto front = pending.front();
if(front == a) ans.first = true;
if(front == b) ans.second = true;
pending.pop();
for(int i = 0; i < v; i++) {
int curr = adj_matrix[front][i];
if(curr == 1) {
    if(pushed_to_queue.count(i) == 0) {
pushed_to_queue[i] = true;
pending.push(i);
    }
}
}
}
return ans;
}

bool pair_no_root_bfs(int** adj_matrix, int v, int a , int b, unordered_map<int, bool> & pushed_to_queue) {
    for(int i = 0; i < v; i++) {
       if(!pushed_to_queue[i]) {
             auto ans = has_path_bfs(adj_matrix, v, i, a, b, pushed_to_queue);
             if(ans.first == true && ans.second == true) return true;
             if(ans.first || ans.second) return false;
       }
    }
    return false;
}
int main() {
    auto inp = input_graph();
    int v= inp.second;
    int a; int b;
    cin >> a >> b;
    unordered_map<int, bool> tmp;
    cout << pair_no_root_bfs(inp.first, v, a , b, tmp);
    return 0;
}
