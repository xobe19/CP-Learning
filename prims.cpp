#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Edge {
    public:
    int source;
    int dest;
    int weight;
    Edge(int a, int b, int c) {
        source = a; dest = b; weight = c;
    }
void print() {
  cout << source << " " << dest << " " << weight << endl;
    }
};

pair<int**, int> input() {
int v; int e;
cin >> v >> e;
int** adj_matrix = new int*[v];
for(int i = 0; i < v ; i++) {
    auto tmp = new int[v];
    for(int j = 0; j < v; j++) {
        tmp[j] = 0;
    }
    adj_matrix[i] = tmp;
}
while (e--)
{
    int a; int b ; int c; cin >> a >> b >> c;
    adj_matrix[a][b] = c;
    adj_matrix[b][a] = c;
}
return {adj_matrix, v};
}

vector<Edge*> prims(int** adj_matrix, int v, int start = 0) {
int weight[v];
bool visited[v];
int parent[v];
for(int i = 0; i < v; i++) {
   weight[i] = INT_MAX ;
   visited[i] = false;
   parent[i] = -1;
}
visited[start] = true;
int visited_count = 1;
while(visited_count != v) {
int curr_min_weight_elem = -1;
int curr_min_weight = INT_MAX;

for(int i = 0; i < v; i++) {
if(adj_matrix[start][i] != 0 && !visited[i]) {

if(weight[i] > adj_matrix[start][i]) {
   weight[i] = adj_matrix[start][i];
   parent[i] = start;
if(adj_matrix[start][i] < curr_min_weight) {
 curr_min_weight = adj_matrix[start][i];
 curr_min_weight_elem = i;
}
}




}
}
if(curr_min_weight_elem == -1) break;
start = curr_min_weight_elem;
cout << "curr_min: " << curr_min_weight_elem << endl;
visited[start] = true;
visited_count++;
}

vector<Edge*> ans(v);

for(int i = 0; i < v; i++) {
ans[i] = new Edge(parent[i], i, weight[i]);
}

return ans;


}

int main() {
    auto inp = input();
    auto ans = prims(inp.first, inp.second);
    for(auto x : ans) {x->print();}
    return 0;
}