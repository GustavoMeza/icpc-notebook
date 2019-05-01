//Tarjan
int tscc, nscc;
stack<int> s;
vi SCC, dfs_num, dfs_low;

void scc(int u) {
    dfs_low[u] = dfs_num[u] = ++tscc;
    s.push(u);
    for(int v : ady[u]) {
        if(!dfs_num[v]) scc(v);
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]) {
        int v; nscc++;
        do {
            v = s.top(); s.pop();
            SCC[v] = nscc;
        } while(u != v);
    }
}

void scc_init() {
    tscc = nscc = 0;
    int n = ady.size();
    SCC.assign(n, 0);
    dfs_num.assign(n, 0);
    dfs_low.assign(n, 0);
}

