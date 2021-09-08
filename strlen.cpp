#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(string s) {
return s.size();
}


int main() {
string s;
getline(cin, s);
cout << f(s);
return 0;
}