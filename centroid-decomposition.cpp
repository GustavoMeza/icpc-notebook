const int MAXN = 1e5+5;

int subtree[MAXN], parent[MAXN];
bool blocked[MAXN];
queue<int> q;
vector<vi> ady;

int makeSubtree(int n, int p) {
    subtree[n] = 1;
    parent[n] = p;
    for(auto v : ady[n])
        if(!blocked[v] && p != v)
            subtree[n] += makeSubtree(v, n);
    return subtree[n];
}

int getCentroid(int root) {
    int centroid, minMaxComp = makeSubtree(root, root);
    q.push(root);
    while(!q.empty()) {
        int n = q.front(); q.pop();
        int maxComp = subtree[root]-subtree[n];
        for(auto v : ady[n])
            if(!blocked[v] && parent[n] != v)
                q.push(v), maxComp = max(maxComp, subtree[v]);
        if(minMaxComp > maxComp) minMaxComp = maxComp, centroid = n;
    }
    return centroid;
}

int solve(int root) {
    return 0;
}

int centroidDesc(int root) {
    int centroid = getCentroid(root);
    printf("%d\n", centroid);
    int ans = solve(centroid);
    blocked[centroid] = true;
    for(auto v : ady[centroid])
        if(!blocked[v])
            ans += centroidDesc(v);
    return ans;
}
