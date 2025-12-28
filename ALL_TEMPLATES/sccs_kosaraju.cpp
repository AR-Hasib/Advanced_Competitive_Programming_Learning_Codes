vector<vector<int>> kosaraju(int n, const vector<vector<int>>& graph) {
    vector<vector<int>> revGraph(n);
    vector<bool> visited(n, false);
    vector<int> order;

    auto dfs1 = [&](auto&& dfs1, int u) -> void {
        visited[u] = true;
        for (int v : graph[u]) {
            revGraph[v].push_back(u);
            if (!visited[v])
                dfs1(dfs1, v);
        }
        order.push_back(u);
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(dfs1, i);
    }

    vector<vector<int>> sccs;
    fill(visited.begin(), visited.end(), false);

    auto dfs2 = [&](auto&& dfs2, int u, vector<int>& component) -> void {
        visited[u] = true;
        component.push_back(u);
        for (int v : revGraph[u]) {
            if (!visited[v])
                dfs2(dfs2, v, component);
        }
    };

    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!visited[u]) {
            vector<int> component;
            dfs2(dfs2, u, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}