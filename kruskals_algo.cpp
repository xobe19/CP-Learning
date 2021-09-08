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

bool edge_comp(Edge* a, Edge* b) {
    return a->weight < b->weight;
}
pair<vector<Edge*> , int>input() {
int v; int e; cin >> v; cin >> e;
vector<Edge*> ans(e);
for(int i = 0; i < e; i++) {
   int a; int b; int c; cin >> a >> b >> c;
   ans[i]= new Edge(a, b, c);
}
sort(ans.begin(), ans.end(), edge_comp);
return {ans, v};


}



vector<Edge*> kruskal(pair<vector<Edge*>, int > inp) {
int local_parent[inp.second];
vector<Edge*> ans;
for(int i = 0; i < inp.second; i++) {
    local_parent[i] = i;
}
for(auto edge : inp.first) {
    if(ans.size() == inp.second - 1) break;
    int parent1 = edge->source;
    int parent2 = edge->dest;
while(parent1 != local_parent[parent1]) {
    parent1 = local_parent[parent1];
}

while(parent2 != local_parent[parent2]) {
    parent2 = local_parent[parent2];
}
if(parent1 == parent2) continue;
else {
ans.push_back(edge);
local_parent[parent2] = parent1;
}

}
return ans;

}


int main() {
auto inp = input();
auto ans = kruskal(inp);
for(auto x : ans) {
   x->print(); 
}
}