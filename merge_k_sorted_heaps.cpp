#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> merge_k_sorted_heaps(vector<queue<int> >&v) {
priority_queue<queue<int> , vector<queue<int> > , greater<queue<int> >> q;
vector<int> ans;
for(auto x : v) {
    q.push(x);
}
while(!q.empty()) {
    auto minim = q.top();
    q.pop();
    auto min_int = minim.front();
    ans.push_back(min_int);
    minim.pop();
   if(!minim.empty())  {
       q.push(minim);
   }
}
return ans;



}


int main() {
    int n;
    cin >> n;
    vector<queue<int> > v; 
    while(n--) {
        int n2;
        cin >> n2;
        queue<int> que;
        while(n2--) {
            int t; cin >> t;
           que.push(t); 
        }
        v.push_back(que);
    }
    auto ans = merge_k_sorted_heaps(v);
    for(auto x : ans) {cout << x << " ";}
}