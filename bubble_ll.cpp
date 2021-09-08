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

bool is_ll_sorted(Node* h) {
    if(h -> next == NULL) return true;
    // recursion
    return h -> data <= h -> next -> data && is_ll_sorted(h -> next);
}

void bubble_sort_ll(Node* h) {
    while(!is_ll_sorted(h)) {
       auto i = h;
       auto j = h -> next;
       while(j != NULL) {
           if(i -> data > j -> data) swap(i-> data,j-> data);
           i = i -> next;
           j = j -> next;
       } 
    }
}

int main() {
    auto inp = f();
    bubble_sort_ll(inp);
    print(inp);
    return 0;
}

