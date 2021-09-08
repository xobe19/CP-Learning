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

bool is_p(vector<int> dat, vector<int>::iterator s, vector<int>::iterator e) {
    if(s >= e) return true;
// base case
if(*s == *e) {
    return true && is_p(dat, s + 1, e-1);
}
else return false;
}
bool is_palindrome_ll(Node* h) {
vector<int> d;
while(h != NULL) {
    d.push_back(h -> data);
    h = h -> next;
}
return is_p(d, d.begin(), d.end() - 1);

}


int main() {
    auto inp = f();
    auto ans = is_palindrome_ll(inp);
    cout << ans << endl;
    return 0;
}