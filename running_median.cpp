#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void running_median(vector<int>&v) {
set<int> data;
int curr_len = 0;
for(int i = 0; i < v.size(); i++) {
    data.insert(v[i]);
    curr_len++;
    if(curr_len%2 == 0) {
        auto it = next(data.begin(), curr_len/2);
        auto it2 = prev(it); 
        cout <<  (float)(*it + *it2)/2.0 << endl;
    }
    else {
        auto it = next(data.begin(), (int)(curr_len/2));
        cout << *it << endl;
    }
}
}
int main() {
int n;
cin >> n;
vector<int> v;
while(n--) {
    int t; cin >> t;
    v.push_back(t);
}
running_median(v);
}