#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<string>> a = {{0, {""}},{1, {""}},{2, {"a", "b", "c"}}, {3,{"d", "e", "f"}}, {4, {"g", "h", "i"}}, {5, {"j", "k", "l"}}, {6, {"m", "n", "o"}}, {7, {"p", "q","r", "s"}}, {8,{"t", "u", "v"}}, {9, {"w", "x", "y","z"}}};

vector<string> f(int n) {
if(n == 0 || n ==1) {
    return {""};
}
// recursive
auto prev = f((int)n/10);
int curr = n%10;
vector<string> ans;
for(string x: prev) {
    for(string y: a[curr]) {
        ans.push_back(x + y);
    }
}
return ans;
}

int main(){
int n;
cin >> n;
auto ans = f(n);
for(string x: ans) {
    cout << x << endl;
}
return 0;
}


