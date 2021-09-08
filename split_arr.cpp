#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> f(int suma, int sumb, vector<int>&left) {
// base case
if(left.size() == 0) return {{suma, sumb}}; 

//recursion
int last = left[left.size() - 1];
left.pop_back();

auto solved1 = f(suma+last, sumb, left);
auto solved2 = f(suma, sumb+last, left);
 solved1.insert(solved1.end(), solved2.begin(), solved2.end());  
 return solved1;
}
bool pred(pair<int, int> x) {
if(x.first == x.second) {
    cout << x.first << endl;
    return true;
}
return false;
}
int main() {
int n;
int suma = 0;
int sumb = 0;
cin >> n;
vector<int> lft;
while(n--) {
    int t;
    cin >> t;

    if(t%5==0) suma+=t; 
    else if(t%3 == 0) sumb+=t;
    else  {
        lft.push_back(t);
    }
}
auto ans = f(suma, sumb, lft);
cout << any_of(ans.begin(),ans.end(), pred);
return 0;
}