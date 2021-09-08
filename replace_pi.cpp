#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string f(string a) {
// base case
if(a.empty()) return "";
// recursion
string solved = f(string(a, 1,a.size()));
if(a[0] == 'p' && solved[0] == 'i') {
solved[0] = '4';
solved = "3.1" + solved;
return solved;
}
return a[0] + solved;
}


int main() {

    string s;
    cin >> s;
    cout << f(s);
    return 0;
}