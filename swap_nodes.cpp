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

Node* swap_nodes(Node *h, int i, int j) {
    Node* head = h;
    if(i !=0 && j - i > 1) {
    Node* i_node = NULL;
    Node* j_node = NULL;
    int curr_ind = 0;
    while(h != NULL) {
       if(curr_ind == i - 1) {
           i_node = h;
       }
       if(curr_ind == j - 1) {
           j_node = h;
       }
       curr_ind++;
       h = h -> next;
    }
swap(i_node -> next -> next, j_node -> next -> next);
swap(i_node -> next , j_node -> next);
    }
    else if( i != 0) {
        Node* i_node = NULL;
        Node* j_node = NULL;
        int curr_ind= 0;
        while(h != NULL) {
     if(curr_ind == i - 1) {
           i_node = h;
       }
       if(curr_ind == j - 1) {
           j_node = h;
       }
       curr_ind++;
       h = h -> next;

        }
        auto tmp = j_node -> next -> next;
        auto tmp2 = j_node -> next;
        j_node -> next -> next = j_node;
      i_node -> next -> next = tmp;
    i_node -> next = tmp2;
    }
    else if(j - i > 1) {
            Node* i_node = NULL;
    Node* j_node = NULL;
    int curr_ind = 0;
    while(h != NULL) {
       if(curr_ind == i) {
           i_node = h;
       }
       if(curr_ind == j - 1) {
           j_node = h;
       }
       if(curr_ind == j) {
           head = h;
       }
       curr_ind++;
       h = h -> next;
    }
swap(i_node -> next, j_node -> next -> next);
swap(i_node, j_node -> next);
    } 
    else {
        Node* i_node = h;
        Node* j_node = h -> next;
        auto tmp = j_node -> next;
        i_node -> next = tmp;
        j_node -> next = i_node;
        head = j_node;
    }

    return head;
}


int main() {
    auto inp = f();
    int i;
    int j;
    cin >> i >> j;
    auto ans = swap_nodes(inp, i , j);
    print(ans);
    return 0;
}