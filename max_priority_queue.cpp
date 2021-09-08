#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class PriorityQueueMax {
public:
vector<int> internal_data;
int getSize() {
    return this -> internal_data.size();
}
bool isEmpty() {
    return this -> internal_data.empty();
}
void insert(int data) {
    internal_data.push_back(data);
    int i = internal_data.size() - 1;
    while((int)((i - 1)/2) >= 0 && internal_data[i] > internal_data[(int)((i - 1)/2)]) {
       swap(internal_data[i], internal_data[(int)((i - 1)/2)]); 
       i = (int)((i - 1)/2);
    }
}
int getMax() {
    return internal_data[0];
}
int deleteMax() {
  swap(internal_data[0], internal_data[internal_data.size() - 1]);
  int bkup = internal_data[internal_data.size() - 1];
  internal_data.pop_back();
  int i = 0;
  int left;
  int right;
  while( i < internal_data.size()) {
   left = 2*i + 1;
   right = 2*i + 2;
   if(left >= internal_data.size()) {
       break;
   }
   else if(right >= internal_data.size()) {
if(internal_data[i] < internal_data[left]) {
    swap(internal_data[i], internal_data[left]);
    i = left;
    continue;
}
else break;
   }
   else {
       int tmp_min = internal_data[left] > internal_data[right] ? left : right;
       if(internal_data[i] < internal_data[tmp_min]) {
     swap(internal_data[i], internal_data[tmp_min]);
     i = tmp_min;
     continue;
       }
       else break;
   }

  }
return bkup;
}
};
void print_vec(vector<int>&v) {
    for(auto x : v) {cout << x << " ";}
    cout << endl;
}
int main() {
    PriorityQueueMax data;
    data.insert(2);
    print_vec(data.internal_data);
    data.insert(3);
    print_vec(data.internal_data);
    data.insert(1);
    print_vec(data.internal_data);
    data.insert(15);
    print_vec(data.internal_data);
    data.insert(4);
    print_vec(data.internal_data);
    data.insert(6);
    print_vec(data.internal_data);
    data.insert(100);
    print_vec(data.internal_data);
    data.insert(99);
    print_vec(data.internal_data);
    data.insert(23);
    print_vec(data.internal_data);
    data.insert(12);
    print_vec(data.internal_data);
    cout << data.deleteMax() << endl;

    print_vec(data.internal_data);
    cout << data.deleteMax() << endl;
    print_vec(data.internal_data);
    cout << data.deleteMax() << endl;
    print_vec(data.internal_data);
    cout << data.deleteMax() << endl;
}