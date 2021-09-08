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

void print_rev_ll(Node* h) {
    // base case
    if(h -> next == NULL) {
        cout << h -> data << " ";
        return;
    }
    // recursion
    print_rev_ll(h -> next);
    cout << h-> data << " ";
}

int main() {
    auto inp = f();
    print_rev_ll(inp);
    return 0;
}