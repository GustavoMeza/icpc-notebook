// requires bfs
ll diameter(ll x) {
    rep(i,0,2) {
        bfs(x);
        rep(j,0,e) if(d[x]<d[q[j]]) x=q[j];
    }
    return d[x];
}
