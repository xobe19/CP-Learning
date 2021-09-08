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

int len(Node* h) {
    if(h == NULL) return 0;
    return 1 + len(h -> next);
}

Node* bubble_ll(Node*h) {
int length = len(h);
auto head = h;
while(length--) {
Node* prev = NULL;
auto curr = head;
auto next = head -> next;
while(curr -> next != NULL) {
if(curr -> data > next -> data) {
   if(prev == NULL) {
    curr -> next = next -> next;
    next -> next = curr;
    head = next; 
    prev = next;
    next = next -> next -> next;
    }
    else {
        curr -> next = next -> next;
        next -> next = curr;
        prev -> next = next;
        prev = next;
        next = next -> next -> next;
    }
}
else {
    prev = curr;
    curr = curr -> next;
    next = next -> next;
}
}
}
return head;
}

int main() {
    auto inp = f();
    auto ans = bubble_ll(inp);
    print(ans);
    return 0;
}

