#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<int**, int> get_input() {
    int v;
    int e;
    cin >> v >> e;
    int** adj_matrix = new int*[v];
    for(int i = 0; i < v; i++) {
        int* tmp = new int[v];
        for(int j = 0; j < v; j++) {
            tmp[j] = 0;
        }
        adj_matrix[i] = tmp;
    }

    while(e--) {
        int a; int b;
        cin >> a >> b;
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    return {adj_matrix, v};
}

vector<int> get_path_bfs(int** adj_matrix, int v, int start, int end) {
queue<int> pending;
unordered_map<int, int> bt;
unordered_map<int, bool> visited;
pending.push(start);
bt[start] = -1;
visited[start] = true;
bool end_in_queue = false;
while(!pending.empty()) {
if(end_in_queue) break;
auto front = pending.front();
visited.insert({front, true});
pending.pop();
for(int i = 0; i < v; i++) {
    if(adj_matrix[front][i] == 1 && visited.count(i) == 0) {
        pending.push(i);

        bt[i] = front;
        if(i == end)  {
            end_in_queue = true;
            break;
        }
    }
}
}
vector<int> ans = {};
int curr = end;
for(auto x : bt) {
   cout << x.first << " " << x.second; 
   cout << endl;
}
cout << " ====";
while(curr != -1) {
   ans.push_back(curr);
    curr = bt[curr];
}
return ans;


}

int main() {
    auto inp = get_input();
    int a; int b; cin >> a >> b;
    auto ans = get_path_bfs(inp.first, inp.second, a, b);
    for(auto x : ans) {cout << x << " ";}
}