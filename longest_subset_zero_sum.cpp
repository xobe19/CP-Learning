#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longest_subset_zero_sum(vector<int>&inp) {
    unordered_map<int, vector<int>*> csum;
    int curr_csum = 0;
    for(int i = 0; i < inp.size(); i++) {
    curr_csum += inp[i];
    if(csum.count(curr_csum) > 0) {
        csum[curr_csum] -> push_back(i);
        continue;
    }
    vector<int>* tmp = new vector<int>();
    tmp->push_back(i);
    csum.insert({curr_csum, tmp});
    }
    int maxim = INT_MIN;
    for(auto x : csum) {
        if(maxim < x.second -> at(x.second -> size() - 1) - x.second -> at(0)) {
            maxim = x.second -> at(x.second -> size() - 1) - x.second -> at(0);
        }
    }
 return maxim;

}

int main() {
    int n;
    cin >> n;
   vector<int> tmp;
    while(n--) {
    int t; cin >> t;
    tmp.push_back(t);
    }
    cout << longest_subset_zero_sum(tmp);
    return 0;
}