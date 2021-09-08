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

void print_bfs(int** adj_matrix,int v, int start) {
queue<int> pending;
unordered_map<int, bool> pushed_to_queue;
pending.push(start);
pushed_to_queue.insert({start, true});
while(!pending.empty()) {
auto front = pending.front();
cout << front << " ";
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
}

int main() {
auto inp = input_graph();
int v= inp.second;
cout << endl;
print_bfs(inp.first, v, 0);
}

