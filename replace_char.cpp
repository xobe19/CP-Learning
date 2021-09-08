#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
string f(string a, char orig, char repl) {
if(a.empty()) return "";
//recursive case
string solved = f(string(a,1), orig, repl);
if(a[0] == orig) {
    return repl + solved;
}
return a[0] + solved;
}

int main() {
string s;
cin >> s;
char orig;
char repl;
cin >> orig >> repl;
cout << f(s, orig, repl) << endl;
return 0;
}