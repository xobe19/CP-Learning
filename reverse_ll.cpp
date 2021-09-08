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


Node* rev_ll_iter(Node* h) {
Node* prev = NULL;
while(h != NULL) {
auto tmp = h -> next;
h -> next = prev;
prev = h;
h = tmp;
}

return prev;
}


pair<Node*, Node*> rev_ll(Node* h) {
    // base case
    if(h -> next == NULL) return {h, h};
    // recursion
    auto reversed = rev_ll(h -> next);
    h -> next = NULL;
    reversed.second -> next = h;
    return {reversed.first, reversed.second -> next};
}

int main() {
    auto inp = f();
   /* auto ans =  rev_ll(inp);
    print(ans.first);
    */
   auto ans2 = rev_ll_iter(inp);
   print(ans2);
}
