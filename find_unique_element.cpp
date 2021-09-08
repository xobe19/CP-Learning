#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f(vector<int> i) {
unordered_map<int, int> p;
for(int x : i) {
    p[x] += 1;
    // if(p.find(x) == p.end()) {
    //   p.insert(x, 1);  
    // }
    // else {
    //  p[x] = p[x] + 1;
    // }

}

for(auto a : p) {
if(a.second == 1) {
    return a.first;
}
}

}

int main() {
int n;
cin >> n;
vector<int> inp;
while(n--) {
int t;
cin >> t;
inp.push_back(t);
}
cout << f(inp) << endl;
return 0;
}