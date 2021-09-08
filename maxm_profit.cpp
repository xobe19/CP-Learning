#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> f(vector<int>&a, int size) {
    cout << size << endl;
if(size == 1) return {a[0], a[0]};
auto solved = f(a, size-1);
if(solved.second <= a[size-1]) {
    return {solved.first + solved.second, solved.second};
}
else {
    if(solved.first < a[size-1]) {
        return {a[size-1], a[size-1]};
    }
    else {
        return solved;
    }
}
}
// wrong
// MUCH SIMPLER SOLUTION USING JUST SORTING
int main() {

int n;
cin >> n;
vector<int> a;
while(n--) {
int t;
cin >> t;
a.push_back(t);
}
auto ans = f(a, a.size());
cout << ans.first << " " << ans.second << endl;
return 0;

}