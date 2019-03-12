int p[MAXN], h[MAXN];

int getParent(int u) {
    if(p[u] == u) return u;
    return p[u] = getParent(p[u]);
}

bool inSameSet(int u, int v) {
    return getParent(u) == getParent(v);
}

void unite(int u, int v) {
    if(inSameSet(u, v)) return;
    int pu = p[u], pv = p[v];
    if(h[pu] == h[pv]) h[pv]++;
    if(h[pu] < h[pv]) p[pu] = pv;
    else p[pv] = pu;
}

void buildDS() {
    for(int i = 1; i <= N; i++) p[i] = i, h[i] = 0;
}
