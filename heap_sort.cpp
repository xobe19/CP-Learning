#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void heap_sort(vector<int> &inp) {
    int len = inp.size();
    int heap_start = 0;
    int heap_end = 0;
    while(heap_end != len - 1) {
        int i = heap_end + 1;
        // up heapify
        while((int)((i-1)/2) >= 0 && inp[(int)((i-1)/2)] > inp[i]) {
            swap(inp[(int)((i-1)/2)], inp[i]);
            i = (int)((i - 1)/2);
        }
        heap_end++;
    }

    while(heap_end != 0) {
        swap(inp[0], inp[heap_end]);
        heap_end--;
        int i = 0;
        // down heapify
        int left;
        int right;
        while(i < heap_end) {
          left = 2*i + 1;
          right = 2*i + 2;
          if(left > heap_end) break;
          else if(right > heap_end) {
            if(inp[i] > inp[left]) {
                swap(inp[i], inp[left]);
                i = left;
                continue;
            } 
            else break;
          }
          else {
              int tmp_min = inp[left] > inp[right] ? right : left;
            if(inp[i] > inp[tmp_min]) {
                swap(inp[i], inp[tmp_min]);

                i = tmp_min;
                continue;
            }
            else break;
          }
        }
    }


}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    while(n--) {int t; cin >> t; v.push_back(t);}
    heap_sort(v);
    for(auto x : v) {cout << x << " ";}
}