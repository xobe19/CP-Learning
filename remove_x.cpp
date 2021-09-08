#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;
string f(string a) {
if(a.empty()) return "";
string solved = f(string(a,1));
if(a[0] == 'x') return solved;
return a[0]+solved;
}

int main() {
string s;
cin >> s;
cout << f(s);
return 0;

}