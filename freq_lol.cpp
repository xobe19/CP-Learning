#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    vector<int> d;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        d.push_back(t);
    }
    map<int, int> data;
    for (auto x : d) {
        data[x] += 1;
    }
    int max = INT_MIN;
    int max_elem = NULL;
   for(auto x : data) {
    if(x.second > max) {
        max = x.second;
        max_elem = x.first;
    }
   }
   cout << max_elem;
   return 0;
}