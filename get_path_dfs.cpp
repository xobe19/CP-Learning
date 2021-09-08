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

vector<int> get_path_dfs(int** adj_matrix, unordered_map<int, bool>&visited, int v, int start, int end) {

    visited[start] = true;
    if(start == end) return {end};
for(int i = 0; i < v; i++) {
if(adj_matrix[start][i] == 1 && visited.count(i) == 0) {
    visited[i] = true;
auto ans = get_path_dfs(adj_matrix, visited, v, i, end);
if(ans.size() != 0) {
    ans.push_back(start);
    return ans;
}
}
}
return {};
}

int main() {
auto inp = get_input();
int a; int b; cin>>a; cin >> b;
unordered_map<int, bool> tmp;
auto ans = get_path_dfs(inp.first, tmp, inp.second, a, b );
for(auto x: ans) {
    cout << x << " ";
}
return 0;
}