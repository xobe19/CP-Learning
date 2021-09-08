#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pair_diff_k(vector<int>&input, int k) {
    unordered_map<int,queue<int>* > index;
    int ans = 0;
    for(int i = 0; i < input.size(); i++) {
        if(index.count(input[i]) > 0) {
            index[input[i]] -> push(i);
            continue;
        }

        queue<int>* tmp = new queue<int>();
        tmp->push(i);
       index.insert({input[i], tmp});
    }

    for(int i = 0; i < input.size(); i++) {
        auto front_indx = index[input[i]] -> front();
        index[input[i]] -> pop();
        if(index.count(input[i] + k) > 0 && index[(input[i] + k)] -> front() > front_indx) {
            ans += index[(input[i] + k)] -> size();
        }
        if(k != 0 && index.count((input[i] - k)) > 0 && index[(input[i] - k)] -> front() > front_indx) {
                 ans += index[(input[i] - k)] -> size(); 
        }
    }

    return ans;





}


int main() {
int n;
cin >> n;
vector<int> inp;
while(n--) {
    int t;
    cin >> t;
inp.push_back(t);
}
int k; cin >> k;
cout << pair_diff_k(inp, k); return 0;
}