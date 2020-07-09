#include <bits/stdc++.h>

using namespace std;

int n, node, aux;
char str[1000];
bool bipartid = true;
map<int, vector<int>> adj;
int visited[1000];
int painted[1000];

void dfs(int s) {
    if(visited[s]) return;
    visited[s] = 1;
    for (auto i : adj[s]) {
        if (painted[i] == painted[s]) {
            bipartid = false;
            return;
        }
        else if (painted[i] == 0)
            painted[i] = -painted[s];
    }

    for (auto i : adj[s])
        dfs(i);
}

int main () {
    scanf("%d", &n);
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> node;
            getchar();
            scanf("%[^\n]s", str);
            char *num = strtok(str, " ");
            while(num != NULL) {
                sscanf(num, "%d", &aux);
                adj[node].push_back(aux);
                adj[aux].push_back(node);
                num = strtok(NULL, " ");
            }
        }

        painted[1] = 1;
        dfs(1);
        if (bipartid)
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;
        
        bipartid = true;
        memset(painted, 0, sizeof(painted));
        memset(visited, 0, sizeof(visited));
        adj.clear();
        scanf("%d", &n);
    }

    return 0;
}
