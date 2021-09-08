#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<char**, pair<int, int> > input() {
    int a; int b; cin >> a >> b;
    char** adj_matrix = new char*[a];
   for(int i = 0; i < a; i++) {
       char* tmp = new char[b];
       string tmp_string;
       cin >> tmp_string;
       for(int j = 0; j < tmp_string.size(); j++) {
           tmp[j] = tmp_string[j];
          // cout << " j : " << j << " " << tmp[j] << " "; 
       }
       adj_matrix[i] = tmp;
   } 
   return {adj_matrix, {a, b}};
}

bool does_exist(string str, pair<int, int> start,unordered_set<string>  &already_visited, char** adj_matrix, int i , int j) {
    if(str.size() == 0) return true;
    if(start.first >= i || start.second >= j || start.first < 0 || start.second < 0) {
        already_visited.clear();
        return false;
    } 
    char tmp = str[0];
    if(adj_matrix[start.first][start.second] == tmp && already_visited.count(to_string(start.first) + "|" + to_string(start.second)) == 0) {
       already_visited.insert(to_string(start.first) + "|" + to_string(start.second)); 
       auto ans = does_exist(str.substr(1), {start.first + 1, start.second}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first , start.second + 1}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first - 1, start.second}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first, start.second - 1}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first + 1, start.second + 1}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first + 1, start.second - 1}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first - 1, start.second + 1}, already_visited, adj_matrix, i, j) ||
does_exist(str.substr(1), {start.first - 1, start.second - 1}, already_visited, adj_matrix, i, j);

if(ans == false) already_visited.clear();
return ans;
    }
    for(auto x : already_visited) {
        cout << x << endl;
    }
    already_visited.clear();
    return false;
}
unordered_set<string> tmp_set;
int main() {
auto inp = input();
string str = "CODINGNINJA";
bool** visited = new bool*[inp.second.first];
for(int i = 0; i < inp.second.first; i++) {
    bool* tmp = new bool[inp.second.second];
    for(int j = 0; j < inp.second.second; j++) {
       tmp[j] = false; 
    }
    visited[i] = tmp;
}
auto ans = false;

for(int i = 0 ; i < inp.second.first; i++) {
    for(int j = 0; j < inp.second.second; j++) {
        if(ans == true) break;
        ans = does_exist(str, {i, j}, tmp_set, inp.first, inp.second.first, inp.second.second);
    }
}

cout << ans;

return 0;
}