#include <bits/stdc++.h>
using namespace std;

map < int, vector < int > > adj;
int visited[10000][10000];
int n, m, p, a, b, k, l;

void dfs (int k, int i) {
    if (visited[i][k]) return;
    visited[i][k] = 1;
    for (auto u : adj[k])
        dfs(u, i);
}

int main () {
    cin >> n >> m >> p;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) dfs (i, i);

    for (int i = 0; i < p; i++) {
        cin >> k >> l;
        if (visited[k][l]) cout << "Lets que lets" << endl;
        else cout << "Deu ruim" << endl;
    }
    return 0;
}