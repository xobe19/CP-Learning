#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b) {
    
auto it1 = a.begin();
auto it2 = b.begin();
vector<int> sorted;
while(it1 != a.end() && it2 != b.end()) {
if(*it1 < *it2) {
    sorted.push_back(*it1);
    it1++;
}
else {
    sorted.push_back(*it2);
    it2++;
}
}
while(it1 != a.end()) {
    sorted.push_back(*it1);
    it1++;
}
while(it2 != b.end()) {
    sorted.push_back(*it2);
    it2++;
}
return sorted;
}


vector<int> f(vector<int> &a) {
if(a.size() <= 1) return a;
int mid = a.size()/2;
auto nons1 = vector<int>(a.begin(), a.begin() + mid);
auto nons2 = vector<int>(a.begin() + mid, a.end());
auto sorted1 = f(nons1);
auto sorted2 = f(nons2);
return merge(sorted1, sorted2);
}

int main() {
    int n;
    cin >> n;
    vector<int> d;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        d.push_back(t);
    }
    vector<int> fin = f(d);
    for(int a: fin) {
        std::cout << a;
    }
    return 0;
}