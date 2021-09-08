#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_max_heap(vector<int> &v , int i) {
int left = 2 * i + 1;
int right = 2 * i + 2;
if(left >= v.size()) {
return true;
}
else if(right >= v.size()) {
return v[i] > v[left];
}
else {
    return v[i] > v[left] && v[i] > v[right] && is_max_heap(v, left) && is_max_heap(v,right);
}
}

int main() {
    int n; cin >> n;
    vector<int> v;
    while(n--) {int t; cin >> t; v.push_back(t);}
    cout << is_max_heap(v, 0);
}