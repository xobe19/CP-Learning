#include <iostream>
#include <bits/stdc++.h>

using namespace std;
unordered_set<string> tmp;
pair<int**, int> input() {
    int a; cin >> a;
    int** adj_matrix = new int*[a];
    for(int i = 0; i < a; i++) {
        int* tmp = new int[a];
        for(int j = 0; j < a; j++) {
         int t; cin >> t;
         tmp[j] = t;
        }
        adj_matrix[i] = tmp;
    }
    return {adj_matrix, a};
}

int piece_weight(int** adj_matrix,pair<int, int> start, unordered_set<string>& already_visited, int a) {
if(already_visited.count(to_string(start.first) + "|" + to_string(start.second)) > 0) return 0;
   if(start.first >= a || start.second >= a || start.first < 0 || start.second < 0) return 0; 
    already_visited.insert(to_string(start.first) + "|" + to_string(start.second));
if(adj_matrix[start.first][start.second] == 0) {
    return 0;
}
int ans = 1;
ans += piece_weight(adj_matrix, {start.first , start.second + 1}, already_visited, a);
ans += piece_weight(adj_matrix, {start.first + 1, start.second }, already_visited, a);
ans += piece_weight(adj_matrix, {start.first , start.second - 1}, already_visited, a);
ans += piece_weight(adj_matrix, {start.first - 1, start.second }, already_visited, a);
ans += piece_weight(adj_matrix, {start.first+1 , start.second + 1}, already_visited, a);
ans += piece_weight(adj_matrix, {start.first - 1, start.second + 1}, already_visited, a);
ans += piece_weight(adj_matrix, {start.first + 1, start.second - 1}, already_visited, a);
ans += piece_weight(adj_matrix, {start.first - 1, start.second - 1}, already_visited, a);

   return ans;





}


int main() {
    auto inp = input();
    int max = INT_MIN;
    for(int i = 0; i < inp.second; i++) {
        for(int j = 0; j < inp.second; j++) {
       // cout << i << " " << j << " "  << endl;
      //  cout << "========" << endl;

        auto ans = piece_weight(inp.first, {i, j}, tmp, inp.second); 
        if(max < ans) max = ans;
        }
    }
    cout << max << endl;
    return 0;
}