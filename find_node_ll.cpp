
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

int findNode(Node* h, int val) {
if(h == NULL) return -1;

// recursion
if(h -> data == val) {
    return 0;
}

int solved = findNode(h -> next, val);
if(solved == -1) return -1;
return solved + 1;
}


int main() {
    auto inp = f();
    int val;
    cin >> val;
    cout << findNode(inp, val) << endl;
    return 0;
}