#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void longest_consec_seq(vector<int>& inp) {
unordered_map<int, bool > data;
unordered_map<int, int> index;
for(int i = 0; i < inp.size(); i++) {
data.insert({inp[i], true});
index.insert({inp[i], i});
}
int start = inp[0];
int end = inp[0];
while(!data.empty()) {
    int first = (*data.begin()).first;
    int tmp_end = first + 1;
    int tmp_before = first - 1;
    while(data.count(tmp_end) > 0) {
        data.erase(tmp_end);
        tmp_end++;
    } 
    tmp_end--;
    while(data.count(tmp_before) > 0) {
        data.erase(tmp_before);
        tmp_before--;
    }
    tmp_before++;
   data.erase(first);
   if(tmp_end - tmp_before > end - start) {
             end = tmp_end;
             start = tmp_before;
   }
  else if(tmp_end - tmp_before == end - start) {
      if(index[tmp_before] < index[start]) {
          end = tmp_end;
          start = tmp_before;
      } 
   }

    
}
cout << start << " " << end;



}

int main() {
    int n;
    cin >> n;
    vector<int> inp;
    while(n--) {
        int t;
        cin >> t;
 inp.push_back(t);
    }
    longest_consec_seq(inp);
    return 0;
}