#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void f(vector<int>&a, int n) {
auto start = a.begin() + n;
while(start != a.end()) {
cout << *(start) << " ";
start++;
}
auto begin = a.begin();
while(begin != a.begin() + n) {
    cout << *(begin) << " ";
    begin++;
}
}


int main() {
int n;
vector<int> a;
cin >> n;
int i ;
cin >> i;
while(n--) {
    int t;
    cin >> t;
    a.push_back(t);
}
f(a,i);
return 0;
}