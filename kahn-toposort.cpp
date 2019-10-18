// modificacion al toposort de kahn
bool kahn_toposort(vector<vi> &g) {
    int n = size(g);
    vi indeg(n);
    forn(u, n) {
        for(auto v: g[u]) {
            indeg[v]++;
        }
    }
    set<int> bst;
    forn(v, n) {
        if(indeg[v] == 0) {
            bst.emplace(v);
        }
    }
    while(!empty(bst)) {
        int u = *begin(bst);
        bst.erase(begin(bst));
        for(auto v: g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                bst.emplace(v);
            }
        }
    }
    return true;
}
