#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10000];
bool visited[10000];
int cont = 0;

void dfs (int s) {
	if (visited[s]) return;
	
	visited[s] = true;
	cont++;
	
	for (auto u: adj[s])
		dfs(u);
}

int main () {
	int n, m;
	int v, w, p;
	int isConnect = 1;
	while(scanf("%d %d", &n, &m) && n && m) {
		for (int i = 0; i < m; i++) {
			cin >> v >> w >> p;
			if (p != 1) {
				adj[v].push_back(w);
				adj[w].push_back(v);
			}
			else adj[v].push_back(w);
		}
		for (int i = 1; i <= n; i++) {
			cont = 0;
			memset(visited, false, sizeof(visited));
			dfs(i);
			if (cont != n) {
				isConnect = 0;
				break;
			}
		}
		cout << isConnect << endl;
		isConnect = 1;
		for (auto &i : adj)
			i.clear();
		for (int j = 0; j <= n; j++)
			visited[j] = false;
	}
}
