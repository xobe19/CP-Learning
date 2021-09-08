#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool f(string orig,string tbc) {
if(tbc.empty()) {
    return true;
}
else {
    if(orig.empty()) {
        return false;
    }
}
auto shit = orig.find(tbc[0]);
if(shit == -1) return false;
return f(orig.substr(shit), tbc.substr(1));
}

int main() {
    string o;
    string t;
    cin >> o >> t ;
    cout << f(o,t);
    return 0;
}