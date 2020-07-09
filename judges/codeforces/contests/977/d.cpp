#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define len(x) (ll)(x).size()

map < ll, vector < ll > > adj;
vector < ll > nodes;
map < ll, bool > visited;
vector < ll > aux;
ll longer = 0, node = 0;
ll n;

void dfs(ll i) {
    if (visited[i]) return;
    visited[i] = true;
    aux.push_back(i);

    for (auto j : adj[i])
        dfs(j);
}

void path () {
    for (auto u : nodes) {
        aux.clear();
        visited.clear();
        dfs(u);
        if (aux.size() > longer) {
            longer = aux.size();
            node = u;
        }
    }
    aux.clear();
    visited.clear();

    dfs(node);
    for (auto i : aux)
        cout << i << " ";
    cout << endl;
}

void solve() {
    cin >> n;

    vector < ll > arr;
    for (ll i = 0; i < n; i++) {
        ll aux;
        cin >> aux;
        arr.push_back(aux);
    }

    for (auto aux : arr) {
        nodes.push_back(aux);

        if (find(arr.begin(), arr.end(), (aux * 2)) != arr.end())
            adj[aux].push_back(aux * 2);
        if (find(arr.begin(), arr.end(), (aux / 3)) != arr.end())
            if (aux % 3 == 0)
                adj[aux].push_back(aux / 3);
    }
    path();
}

int main () {
    solve();
}