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

Node* rev_ll(Node* h) {
// base case
if(h -> next == NULL) return h;
// recursion
auto tail = h -> next;
auto reversed = rev_ll(h -> next);
h -> next = NULL;
tail -> next = h;
return reversed;
}

Node* rev_ll_k(Node*h, int i) {
Node* fin_h = NULL;
Node* fin_t = NULL;
Node* tmp_h = NULL;
Node* tmp_t = NULL;

while(h != NULL) {
    int k = i;
    while(k-- && h != NULL) {
        if(tmp_h == NULL) {
            tmp_h = h;
            tmp_t = h;
        }
        else {
            tmp_t -> next = h;
            tmp_t = tmp_t -> next;
        }
        h = h -> next;
    }
    
    tmp_t -> next = NULL;
    auto tmp_ans = rev_ll(tmp_h);
    if(fin_h == NULL) {
        fin_h = tmp_ans;
        fin_t = tmp_h;
    }
    else {
        fin_t -> next = tmp_ans;
        fin_t = tmp_h;
    }
    tmp_h = NULL;
    tmp_t = NULL;

    fin_t -> next = NULL;
}
fin_t -> next = NULL;
return fin_h;
}
int main() {
    auto inp = f();
    int k;
    cin >> k;
    if(k == 0) {
        print(inp);
        return 0;
    }
    auto ans = rev_ll_k(inp, k);
    print(ans);
    return 0;
}