#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> f(vector<int>&a) {
unordered_map<int,int> mp;
stack<  pair<int, int> > c;
for(int i = 0; i < a.size(); i++) {
    if(c.empty()) c.push({i, 1});
    else {
        pair<int, int> tbp = {i , 1};
        auto tp = c.top();
        while(!c.empty() && a[tp.first] < a[i]) {
           tbp.second += tp.second; 
           c.pop();
           mp[tp.first] = tp.second;
           if(c.empty()) break;
           tp = c.top();
        }
        c.push(tbp);
    }
}
while(!c.empty()) {
    mp[c.top().first] = c.top().second;
    c.pop();
}
vector<int> ans(a.size());
for(auto x : mp) {
ans[x.first] = x.second;
}
return ans;
}
void print_vec(vector<int>&a) {
    for(int x: a) {
   cout << x << " ";
    }
}
int main() {
int n;
cin >> n;
vector<int> a;
while(n--) {
    int t;
    cin >> t;
    a.push_back(t);
}
auto ans = f(a);
print_vec(ans);
return 0;
}