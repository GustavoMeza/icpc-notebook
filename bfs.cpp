ll d[maxn], vis[maxn], q[maxn],s,e,k,p[maxn];
void bfs(vector<ll> us) {
    s=e=0; k++;
    for(ll u : us)
        d[u]=0,p[u]=0,vis[u]=k,q[e++]=u;
    while(s<e) {
        ll u=q[s++];
        for(auto v: ady[u]) if(vis[v]!=k)
            d[v]=d[u]+1, p[v]=u, vis[v]=k, q[e++]=v;
    }
}
