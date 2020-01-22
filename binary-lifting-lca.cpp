const ll maxn=2e5+5, L=20;
vector<ll> ady[maxn];

ll P[L][maxn], D[maxn];
ll query_binlift(ll u, ll v) {
    if(D[u] > D[v]) swap(u,v);
    for(ll i=L-1; i>=0; i--) if(D[u] <= D[P[i][v]]) v=P[i][v];
    for(ll i=L-1; i>=0; i--) if(P[i][u] != P[i][v]) u=P[i][u], v=P[i][v];
    return u == v ? u : P[0][u];
}
void build_binlift(ll x) {
    bfs({x});
    rep(i,1,n+1) P[0][i]=p[i], D[i]=d[i];
    rep(i,1,L) rep(j,1,n+1) P[i][j]=P[i-1][P[i-1][j]];
}
