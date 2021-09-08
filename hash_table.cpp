#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class HashMapNode{
public: 
string key;
int data;
HashMapNode* next;
HashMapNode(string key, int data) {
    this -> key = key;
    this -> data = data;
    this -> next = NULL;
}
~HashMapNode() {
    delete this -> next;
}
};
class HashMap {
public:
int capacity = 5;
double load_factor;
int count;
HashMapNode** internal_data;
HashMap() {
    internal_data = new HashMapNode*[5];
for(int i = 0; i < 5; i++) {
    internal_data[i] = NULL;
}
this -> load_factor = 0;
this -> count = 0;
}
static const int p = 37;
int hash_string(string a) {
int hash = 0;
int curr_coefficient = 1;
for(int i = a.size() - 1; i >= 0; i--) {
hash += a[i] * curr_coefficient;
curr_coefficient *= p;

hash %= capacity;
curr_coefficient %= capacity;
}
return hash % capacity;
}

void insert(string key, int value) {
    int tmp_hash = hash_string(key);
    auto head = internal_data[tmp_hash];
    auto head_bkup = head;
    while(head != NULL) {
        if(head -> key == key) {
            head -> data = value;
            return;
        }
        head = head -> next;
    }
    auto neww = new HashMapNode(key, value);
    this -> count++;
    neww -> next = head_bkup;
    internal_data[tmp_hash] = neww;
    this -> load_factor = (1.0 * count)/capacity; 
    if(this -> load_factor > 0.67) this->rehash();
}

int get(string key) {
int tmp_hash = hash_string(key);
auto head = internal_data[tmp_hash];
while(head != NULL) {
    if(head -> key == key) {
        return head -> data;
    }
head = head -> next;
}
return 0;
}

void remove(string key) {
    int tmp_hash = hash_string(key);
    auto head = internal_data[tmp_hash];
    HashMapNode* prev = NULL;
    while(head != NULL) {
        if(head -> key == key) {
            if(prev == NULL) {
                internal_data[tmp_hash] = head -> next;
            }
            else {
                prev -> next = head -> next;
            }
            head -> next = NULL;
            delete head;
        }
        prev = head;
        head = head -> next;
    }
}

void rehash() {
HashMapNode** tmp_arr = internal_data;
internal_data = new HashMapNode*[capacity * 2];
int oldCapacity = capacity;
capacity *= 2;
for(int i = 0; i < capacity; i++) {
    internal_data[i] = NULL;
}
for(int i = 0;  i< oldCapacity; i++) {
    auto head = tmp_arr[i];
    while(head != NULL) {
        this -> insert(head -> key, head -> data);
        head = head -> next;
    }
   delete head; 
}

delete [] tmp_arr;
//vectors are good bruh
// c++ array suck
}

};


int main() {
    HashMap hitesh;
    hitesh.insert("pavani", 69);
    cout << hitesh.load_factor << endl;
    hitesh.insert("shivani", 45);
    cout << hitesh.load_factor << endl;
    hitesh.insert("RaSHMI VERMA", 19999999);
    cout << hitesh.load_factor << endl;
    hitesh.insert("saba", 34);
    cout << hitesh.load_factor << endl;
    hitesh.insert("akhila sripada", 300);
    cout << hitesh.load_factor << endl;
    hitesh.insert("shivani C", 3000);
    cout << hitesh.load_factor << endl;
    hitesh.insert("ranjani", 49);
    cout << hitesh.load_factor << endl;
    hitesh.insert("keerthana", 349);
    cout << hitesh.load_factor << endl;
    hitesh.insert("keerthana fat", 420);
    cout << hitesh.load_factor << endl;
    hitesh.insert("pavani", 70);
    cout << hitesh.load_factor << endl;
    cout << hitesh.get("saba");
     hitesh.remove("pavani");
    cout << hitesh.get("saba");
    cout << hitesh.get("pavani");
   return 0; 
}