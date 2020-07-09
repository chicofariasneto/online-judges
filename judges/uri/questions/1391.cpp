#include <bits/stdc++.h>

using namespace std;

int n, m, s, d, u, v, p;
int menor;
int INF = 1000000;
map < int, vector < pair < int, int > > > adj;
int visited[500];
int distances[500];
int dad[500];

int main () {
    while (cin >> n >> m && n && m) {
        cin >> s >> d;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            adj[u].push_back({ v, p });
        }

        for (int i = 0; i < n; i++) distances[i] = INF;
        distances[s] = 0;
        priority_queue < pair < int, int > > q;
        q.push({ 0, s });

        while (!q.empty()) {
            int a = q.top().second; q.pop();
            if (visited[a]) continue;
            visited[a] = 1;
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                if (distances[a] + w <= distances[b]) {
                    distances[b] = distances[a] + w;
                    dad[b] = a;
                    q.push({ -distances[b], b });
                }
            }
        }
        menor = distances[d];
        while (menor == distances[d] && distances[d] != INF) {
            int position = 0, aux = d;
            while (aux != s) {
                int seg = dad[aux];
                for (auto u : adj[dad[aux]]) {
                    if (u.first == aux) {
                        adj[dad[aux]].erase(adj[dad[aux]].begin() + position);
                        break;
                    }
                    position++;
                }
                position = 0;
                aux = seg;
            }
            for (int i = 0; i < n; i++) {
                visited[i] = dad[i] = 0;
                distances[i] = INF;
            }
            distances[s] = 0;
            priority_queue < pair < int, int > > q;
            q.push({ 0, s });
            while (!q.empty()) {
                int a = q.top().second; q.pop();
                if (visited[a]) continue;
                visited[a] = 1;
                for (auto u : adj[a]) {
                    int b = u.first, w = u.second;
                    if (distances[a] + w < distances[b]) {
                        distances[b] = distances[a] + w;
                        dad[b] = a;
                        q.push({ -distances[b], b });
                    }
                }
            }
        }
        if (distances[d] == INF) cout << "-1" << endl;
        else cout << distances[d] << endl;
        for (int i = 0; i < n; i++) {
            visited[i] = dad[i] = 0;
        }
        adj.clear();
    }
    return 0;
}