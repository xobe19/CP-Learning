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

Node* del_m_nodes(Node* h, int i, int j) {
Node* fin_h = NULL;
Node* fin_t = NULL;

while(h != NULL) {
int m = i;
int n = j;
while(m-- && h != NULL) {
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
while(n-- && h != NULL) {
    auto temp = h;
    h = h -> next;
   delete temp;
}
}
fin_t -> next = NULL;
return fin_h;


}

int main() {
auto inp = f();
int m;
int n;
cin >> m >> n;
auto ans = del_m_nodes(inp, m, n);
print(ans);
return 0;
}
