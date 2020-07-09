#include <bits/stdc++.h>

using namespace std;

int n, m;
string str1, str2; 
int cont = 0;
map<string, vector<string>> adj;
map<string, bool> visited;

void dfs(string s) {
    if(visited[s]) return;
    visited[s] = true;

    for (auto i : adj[s])
        dfs(i);
}
string aux;
int main () {
    cin >> n >> m;
    for (int i= 0; i < m; i++) {
        cin >> str1 >> str2 >> str2;
        adj[str1].push_back(str2);
        adj[str2].push_back(str1);
    }

    for (auto i = adj.begin(); i != adj.end(); i++) {
        if(!visited[i->first]) {
            dfs(i->first);
            cont++;
        }
    }
    
    cout << cont << endl;
    return 0;
}
