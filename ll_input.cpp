#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
int data;
Node* next;
Node(int d) {
this -> data = d;
this -> next = NULL;
}
};
Node* f() {

Node* head = NULL;
Node* curr = NULL; 
while(true) {
    int n;
    cin >> n;
    if(n == -1) break;
    if(head != NULL) {

        curr -> next = new Node(n);
        curr = curr -> next;
    }
    else {
        head = new Node(n);
        curr = head;
    }
}
return head;

}

void print(Node* h) {
while(h != NULL) { 
    cout << h -> data;
 h = h -> next;
}
}

int len_ll(Node* head) {
    int c=0;
    while(head != NULL) {
        c++;
        head = head -> next;
    }
    return c;
}

int l(Node* head) {
// base case
if(head == NULL) return 0;
// recursion
return 1 + l(head -> next);
}
Node* ins(Node* head, int i , int elem) {
// base case
if(i == 0) {
    Node* tbs = new Node(elem);
    tbs -> next = head;
    return tbs;
}

//recursion
Node* solved = ins(head -> next, i-1, elem);
head -> next = solved;
return head;
}
int main() {
    Node* ans = f();
   int i;
   cin >> i;
   int elem;
   cin >> elem;
   print(ins(ans, i, elem));
    return 0;
}  