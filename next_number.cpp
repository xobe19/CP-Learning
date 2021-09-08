#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
int data;
Node* next;
Node(int d) {
this -> data = d;
this -> next = NULL;
}
};
Node* f() {

Node* head = NULL;
Node* curr = NULL; 
while(true) {
    int n;
    cin >> n;
    if(n == -1) break;
    if(head != NULL) {

        curr -> next = new Node(n);
        curr = curr -> next;
    }
    else {
        head = new Node(n);
        curr = head;
    }
}
return head;

}

void print(Node* h) {
while(h != NULL) { 
    cout << h -> data;
 h = h -> next;
}
}


pair<Node*, int> next_number(Node* h) {
if(h -> next == NULL) {
    if(h -> data == 9) {
        h -> data = 0;
        return {h, 1};
    }
    else {
      (h -> data)++;
      return {h, 0};
    }
}
else {
auto solved = next_number(h -> next);
if(solved.second == 0) {
    h -> next = solved.first;
    return {h, 0};
}
else {
    h -> next = NULL;
    auto tmp = next_number(h);
   tmp.first -> next = solved.first;
   return {tmp.first, tmp.second};
}
}
}

int main() {
    auto inp = f();
    auto ans =  next_number(inp);
    if(ans.second == 1) {
        auto tmp = new Node(1);
        tmp -> next = ans.first;
        print(tmp);
    }
    else {
        print(ans.first);
    }
    return 0;
}