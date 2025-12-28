vector<vector<int>> primMST(int n, const vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n); // adjacency list

    for (auto &e : edges) {
        int w = e[0], u = e[1], v = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // because undirected
    }

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);     // track parent of each node
    vector<int> minEdge(n, INT_MAX); // min weight to connect each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, 0}); // {weight, node}
    minEdge[0] = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, weight] : adj[u]) {
            if (!visited[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
            }
        }
    }

    vector<vector<int>> mst;
    for (int v = 1; v < n; v++) {
        if (parent[v] != -1) {
            mst.push_back({minEdge[v], parent[v], v}); // {weight, u, v}
        }
    }

    return mst;
}

