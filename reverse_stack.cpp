#include <iostream>

#include <bits/stdc++.h>

using namespace std;

void reverse_stack(stack<int>& a) {
stack<int> buffer;
int size = a.size();
int reversed = 0;
while(reversed != size) {
    int i = size - reversed - 1;
    int last = a.top();
    a.pop();
    while(i--) {
      buffer.push(a.top());
      a.pop();
    }
    a.push(last);
   while(!buffer.empty()) {
      a.push(buffer.top());
      buffer.pop();
   }
   reversed++;
}
}


int main() {
stack<int> inp;
int n;
cin >> n;
while(n--) {
    int t;
    cin >> t;
    inp.push(t);
}
reverse_stack(inp);
while(!inp.empty()) {
    cout << inp.top() << " ";
    inp.pop();
}
return 0;

}