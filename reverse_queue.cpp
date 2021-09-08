#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverse_queue(queue<int> &a) {
 if(a.size() == 1) return;
  
  int x = a.front();
  a.pop();
  reverse_queue(a);
  a.push(x);

}

int main() {
    int n;
    cin >> n;
    queue<int> inp;
    while (n--)
    {
    int t;
    cin >> t;
        inp.push(t);
    }
   int syz = inp.size();
 reverse_queue(inp);
while(syz--) {
    cout << inp.front() << " ";
    inp.pop();
}
return 0;
}