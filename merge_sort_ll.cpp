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

Node* div_and_ret_mid_node(Node* h) {
    Node* fast = h;

    Node* slow = h;
    Node* slow_bef = NULL;
    while(fast != NULL && fast -> next != NULL && slow != NULL) {
        fast = fast -> next -> next;
        slow_bef = slow;
        slow = slow -> next;
    }
    slow_bef -> next = NULL;
    return slow;
}

Node* merge(Node* h1, Node*h2) {
Node* final_head = NULL;
Node* final_tail = NULL;
while(h1 != NULL && h2 != NULL) {
if(final_head == NULL) {
    if(h1 -> data > h2 -> data) {
        final_head = h2;
        final_tail = h2;
        h2 = h2 -> next;
    }
    else {
        final_head = h1;
        final_tail = h1;
        h1 = h1 -> next;
    }

}
else {
    if(h1 -> data > h2 -> data) {
       final_tail -> next = h2;
       final_tail = final_tail -> next;   
       h2 = h2 -> next;
    }
    else {
        final_tail -> next = h1;
        final_tail = final_tail -> next;
        h1 = h1 -> next;
    }
}
}
if(h1 != NULL) {
    final_tail -> next = h1;
}
if(h2 != NULL) {
    final_tail -> next = h2;
}
return final_head;
}
Node* merge_sort_ll(Node*h) {
// base case
if(h == NULL || h -> next == NULL) return h;
// recursion
auto mid = div_and_ret_mid_node(h);
auto h1 = merge_sort_ll(h);
auto h2 = merge_sort_ll(mid);
return merge(h1, h2);
}



int main() {
auto inp = f();
auto ans = merge_sort_ll(inp);
print(ans);
return 0;
}
