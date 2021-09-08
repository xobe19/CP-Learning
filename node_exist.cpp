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
void print(Node* h) {
while(h != NULL) { 
    std::cout << (h -> data);
 h = h -> next;
}
}

Node* f() {
Node* head = NULL;
Node* curr = NULL;

while(true) {
    int n;
    cin >> n;
    if(n==-1) break;
    Node* t = new Node(n);
    if(head == NULL) {
        head = t;
        curr = t;
    }
    else {
        curr -> next = t;
        curr = curr -> next;
    }
}
return head;

}

Node* appnd(Node* head, int k) {
Node* nptr = NULL;
Node* tail = NULL;
Node* tailptr = head;
int tailIndx = 0;
while(tailptr != NULL) {
    if(nptr != NULL) nptr = nptr -> next;
if(tailIndx - k == 0) {
 nptr = head; 
}

tailptr = tailptr -> next;
tail = tailptr == NULL ? tail : tailptr;
tailIndx++;
}
if(tail != NULL) {
    tail -> next = head;
    head = nptr -> next;
    nptr -> next = NULL;
    return head;
}
else return NULL;
}


int main() {
auto ll = f();
int k;
cin >> k;
auto ans = appnd(ll, k);
print(ans);
return 0;
}