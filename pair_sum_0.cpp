#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int , pair<int, int> > data;
    vector<int> input;
    int n; cin >> n;
    while(n--) {int t; cin >> t; input.push_back(t);}
    for(auto x : input) {
        if(x > 0) {
            data[x].first += 1;
        }
        else if(x < 0) {
            data[-x].second += 1;
        }
        else {
            data[x].first += 1;
        }

    }
    int ans = 0;
    for(auto y : data) {
         if(y.first == 0) ans +=  (y.second.first * (y.second.first-1)) / 2;
        else ans += (y.second.first * y.second.second);
    }
    cout << ans << endl;
    return ans;
}