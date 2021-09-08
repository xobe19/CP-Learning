#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int buy_ticket(queue<pair<int, bool> >&v, priority_queue<int>&q) {
int time = 0;

while(!v.front().second || q.top() > v.front().first) {
auto front = v.front();
if(q.top() > front.first) {
v.pop();
v.push(front);
continue;
}
else {
    q.pop();
    v.pop();
    time++;
    continue;
}
}
return time+1;

}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    queue<pair<int, bool> > v;
    priority_queue<int>q;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        q.push(t);
        if(i != k) {
            v.push({t, false});
        }
        else v.push({t, true});
    }
    cout << buy_ticket(v,q);
}