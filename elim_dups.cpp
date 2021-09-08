#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int n) {
        this -> data = n;
        this -> next = NULL;
    }
};
Node* f() {
Node* head = NULL;
Node* tail = NULL;
while(true) {
    int n;
    cin >> n;
    if(n == -1) break;
    if(head == NULL) {
        head = new Node(n);
        tail = head;
    }
    else {
        auto tmp = new Node(n);
        tail -> next = tmp;
        tail = tail -> next;
    }
}
return head;

}


void print(Node* h) {
    while(h != NULL) {
        cout << h -> data << " ";
        h = h -> next;
    }
}
Node* elim_dups(Node* h) {
    // base case
if(h -> next == NULL) return h;
// recursion
auto solved = elim_dups(h -> next);
if(solved -> data == h -> data) {
    return solved;
}
else {
    h -> next = solved;
    return h;
}
}

int main() {
auto inp = f();
auto ans = elim_dups(inp);
print(ans);
return 0;
}