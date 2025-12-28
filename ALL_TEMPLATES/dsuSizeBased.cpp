class UnionFind{
    private: vector<int> p, size;
    public:
        UnionFind(int n){
            size.assign(n, 1); p.assign(n, 0);
            iota(p.begin(), p.end(), 0);    // parent of each node set to itself
        }

        int findSet(int i){     // return the parent(root) of the set i belongs to
            return (p[i] == i) ? i:p[i] = findSet(p[i]);
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j){
            if(!isSameSet(i, j)){
                int x = findSet(i), y = findSet(j);
                if(size[x] < size[y]) swap(x, y);
                p[y] = x;
                size[x] += size[y];
            }
        }
        int getSize(int i) {
            return size[findSet(i)];
        }
};