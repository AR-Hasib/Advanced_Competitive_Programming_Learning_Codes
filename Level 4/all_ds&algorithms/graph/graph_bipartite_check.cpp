
vector<int> color(n+1, -1);
color[0] = 0;
auto dfs = [&] (auto &&dfs, int node, int parent, bool& isBipartite, int &white, int &black) -> void{
    color[node] = color[parent] ^ 1;
    if(color[node]) black++;
    else white++;

    for(auto &neigh:edges[node]){
        if(color[neigh] != -1){
            if(color[neigh] == color[node]){
                isBipartite = false;
                return;
            }
            continue;   // it has a color means it is already visited 
        }
        dfs(dfs, neigh, node, isBipartite, white, black);
    }
};

for(int i=1; i<=n; i++){
    if(color[i] != -1) continue;

    bool isBipartite = true;
    int white = 0, black = 0; // count of alternate node
    dfs(dfs, i, 0, isBipartite, white, black);
}