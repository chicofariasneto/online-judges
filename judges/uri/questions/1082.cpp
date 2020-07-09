#include <bits/stdc++.h>

using namespace std;

int n;
int v, e;
char aux = 'a';
int it = 1;
char c1, c2; 
int cont = 0;
vector<char> lista;
map<char, vector<char>> adj;
map<char, bool> visited;

void dfs(char c) {
    if(visited[c]) return;
    visited[c] = true;
    lista.push_back(c);

    for (auto i : adj[c])
        dfs(i);
}

int main () {
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> v >> e;
        for (int i = 0; i < v; i++) {
            adj[aux].push_back(aux);
            aux++;
        }

        for (int i= 0; i < e; i++) {
            cin >> c1 >> c2;
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }

        cout << "Case #" << it++ << ":" << endl;
        for (auto i = adj.begin(); i != adj.end(); i++) {
            if(!visited[i->first]) {
                dfs(i->first);
                sort(lista.begin(), lista.end());
                for (auto i : lista) {
                    cout << i << ",";
                }
                cout << endl;
                lista.clear();
                cont++;
            }
        }
        cout << cont << " connected components" << endl << endl;
        adj.clear();
        visited.clear();
        aux = 'a';
        cont = 0;
    }
    return 0;
}