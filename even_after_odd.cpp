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

Node* even_aft_odd(Node* h) {
    Node* odd_h = NULL;
    Node* odd_t = NULL;
    Node* even_h = NULL;
    Node* even_t = NULL;
    while(h != NULL) {
        if(h -> data % 2 == 0) {
            if(even_h == NULL) {
                even_h = h;
                even_t = h;
            }
            else {
                even_t -> next = h;
                even_t = even_t -> next;
            }
        }
        else {
            if(odd_h == NULL) {
                odd_h = h;
               odd_t = h;
            }
            else {
                odd_t -> next = h;
                odd_t = odd_t -> next;
            }
        }
        h = h -> next;
    }
    if(odd_t != NULL) odd_t -> next = even_h;
    if(even_t != NULL) even_t -> next = NULL;
    return odd_h == NULL ? even_h : odd_h;
}


int main() {
    auto inp = f();
    auto ans = even_aft_odd(inp);
    print(ans);
    return 0;
}