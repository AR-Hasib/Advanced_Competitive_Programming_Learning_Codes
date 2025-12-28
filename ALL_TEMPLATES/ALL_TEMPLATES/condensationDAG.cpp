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