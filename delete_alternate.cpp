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

Node* delete_alternate(Node* h) {
    int c = 0;
    Node* fin_h = NULL;
    Node* fin_t = NULL;
    while(h != NULL) {
        if(c % 2 == 0) {
            if(fin_h == NULL) {
                fin_h = h;
                fin_t = h;
            }
            else {
                fin_t -> next = h;
                fin_t = fin_t -> next;
            }
           h = h -> next;
        }
        else  {
            auto tmp = h;
            h = h -> next;
            delete tmp;
        }
        c++;
    }
    fin_t -> next = NULL;
    return fin_h;
}
int main() {
    auto inp = f();
    auto ans = delete_alternate(inp);
    print(ans);
    return 0;
}