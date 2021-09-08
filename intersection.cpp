#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void f(vector<int>&a, vector<int>&b) {
    unordered_map<int, int> one;
    unordered_map<int, int> two;
    for(int x: a) {
        one[x] += 1;
    }
    for(int y: b) {
        two[y] += 1;
    }
   for(auto z: one) {
     if(two.find(z.first) != two.end()) {
         int what = min(z.second, two[z.first]);
          while(what--){
              cout << z.first << " ";
          }
     }
   }
}



int main(){
int n;
cin >> n;
vector<int> a;
while(n--) {
    int t;
    cin >> t;
    a.push_back(t);
}
int m;
vector<int> b;
cin >> m;
while(m--) {
    int t;
    cin >> t;
    b.push_back(t);
}
f(a, b);
return 0;
}