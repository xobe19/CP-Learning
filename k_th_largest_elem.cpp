#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int k_largest(vector<int>&v, int k) {
priority_queue<int, vector<int>, greater<int> > q;
for(auto x : v) {
    if(q.size() < k) {
         q.push(x);
    }
    else {
        if(x > q.top()) {
            q.pop();
            q.push(x);
        }
    }
}
return q.top();
}

int main() {
    int n; cin >> n;
    vector<int> v;
    while(n--) {int t; cin >> t; v.push_back(t);}
    int k; cin >> k;
    cout << k_largest(v, k);
}