int source = 0;
vector<int> dist(n, INF);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
pq.push({0, source});   // distance, node
dist[source] = 0;
while(!pq.empty()){
    int currDist = pq.top().first;
    int u = pq.top().second;    // current node
    pq.pop();
    
    if(dist[u] < currDist) continue;   // already have shorter distance
    for(auto &neigh:edges[u]){
        int v = neigh.first;
        int uvDist = neigh.second+currDist;
    
        if(uvDist < dist[v]){
            dist[v] = uvDist;
            pq.push({dist[v], v});
        }
    }
}


///// functional version /////
void djk(int source, vector<vector<pair<int, int>>> &edges, vector<int> &dist, vector<int> &parent){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});   // distance, node
    dist[source] = 0;
    while(!pq.empty()){
        int currDist = pq.top().first;
        int u = pq.top().second;    // current node
        pq.pop();

        if(dist[u] < currDist) continue;   // already have shorter distance,
        for(auto &neigh:edges[u]){
            int v = neigh.first;
            int uvDist = neigh.second+currDist;

            if(uvDist < dist[v]){
                dist[v] = uvDist;
                parent[v] = u;	// use for path
                pq.push({dist[v], v});
            }
        }
    }
}