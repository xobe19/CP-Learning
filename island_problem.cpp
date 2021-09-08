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


void dfs_visit(int** adj_matrix, int v, bool* visited, int start) {
for(int i = 0; i < v; i++) {
    if(adj_matrix[start][i] == 1 && !visited[i]) {
        visited[i] = true;
   dfs_visit(adj_matrix, v, visited, i);
    }
}
}







int find_num(int** adj_matrix, int v) {
    int ans = 0;
auto visited = new bool[v];
for(int i = 0; i < v; i++) {visited[i] = false;}
for(int i = 0; i < v; i++) {
    if(!visited[i]) {
        cout << i << " ";
        ans += 1;
   dfs_visit(adj_matrix, v, visited, i);
    }
}

return ans;
}


int main() {
    auto inp = get_input();
    cout << find_num(inp.first, inp.second);
    return 0;
}
