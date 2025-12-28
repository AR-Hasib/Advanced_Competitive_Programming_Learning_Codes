#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> kosaraju(int n, const vector<vector<int>>& graph) {
    vector<vector<int>> revGraph(n);
    vector<bool> visited(n, false);
    vector<int> order;

    // 1st DFS to compute finishing times
    auto dfs1 = [&](auto&& dfs1, int u) -> void {
        visited[u] = true;
        for (int v : graph[u]) {
            revGraph[v].push_back(u); // Build reverse graph
            if (!visited[v])
                dfs1(dfs1, v);
        }
        order.push_back(u); // Finished node
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(dfs1, i);
    }

    // 2nd DFS on reverse graph in decreasing order of finish time
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



//////////////////// condensation DAG
// it needs kosaraju algo
vector<vector<int>> buildCondensationDAG(int n, const vector<vector<int>>& graph) {
    vector<vector<int>> sccs = kosaraju(n, graph);

    // Map each node to its SCC ID
    vector<int> nodeToSCC(n, -1);
    for (int i = 0; i < sccs.size(); ++i) {
        for (int node : sccs[i]) {
            nodeToSCC[node] = i;
        }
    }

    // Build edges of condensation DAG (avoid duplicate edges)
    int sccCount = sccs.size();
    vector<set<int>> dagSet(sccCount);
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            int from = nodeToSCC[u];
            int to = nodeToSCC[v];
            if (from != to) {
                dagSet[from].insert(to);
            }
        }
    }

    // Convert set-based edges to vector-based DAG
    vector<vector<int>> dag(sccCount);
    for (int i = 0; i < sccCount; ++i) {
        dag[i] = vector<int>(dagSet[i].begin(), dagSet[i].end());
    }

    return dag;
}

