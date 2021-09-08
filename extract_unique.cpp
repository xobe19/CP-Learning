#include <iostream>
#include <bits/stdc++.h>
using namespace std;


string extract_unique(string inp) {
unordered_map<char, bool> seen;
string out;
for(auto x : inp) {
    if(seen.count(x) > 0) {
        // do nothing
    }
    else {
        out += x;
        seen[x] = true;
    }
}
return out;
}

int main() {
    string inp;
    cin >> inp;
    cout << extract_unique(inp);
    return 0;
}