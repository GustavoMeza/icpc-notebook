// requires bfs
ll diameter() {
    ll a=0, b=0;
    bfs({1ll});
    rep(j,0,e) if(d[x]<d[q[j]]) a=q[j];
    bfs({a});
    rep(j,0,e) if(d[x]<d[q[j]]) b=q[j];
    return d[b]; // diametro=a->b
}
