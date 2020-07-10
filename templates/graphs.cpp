void dfs(ll i) {
    if (visited[i]) return;
    visited[i] = true;
    nodes.push_back(i);

    for (auto j : adj[i])
        dfs(j);
}

void bfs(ll x) {
    queue < ll > q;
    ll distance[MAXN];
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while (!q.empty()) {
        ll s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s] + 1;
            q.push(u);
        }
    }
}

void dijkstra() {
    for (ll i = 1; i <= n; i++) distance[i] = MAXN;
    distance[x] = 0;
    q.push({ 0, x });
    while (!q.empty()) {
        ll a = q.top(); q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : adj[a]) {
            ll b = u.x, w = u.y;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({ -distance[b], b });
            }
        }
    }
}