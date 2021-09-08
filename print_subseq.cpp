#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
vector<string> f(string a) {
if(a == "") {
    vector<string> ans;
    ans.push_back("");
    return ans;
};
int syz = a.size();
auto prev = f(a.substr(0, syz - 1));
int s = prev.size();
for(int i = 0; i < s; i++) {
    prev.push_back(prev[i] + a[a.size() - 1]);
}
return prev;
}

int main() {
string s;
cin >> s;
auto ans = f(s);
ans.pop_back();
for(string x: ans) {
    cout << x << endl;
}
return 0;
}