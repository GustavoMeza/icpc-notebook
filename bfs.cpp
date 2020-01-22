ll d[maxn], vis[maxn], p[maxn], q[maxn], s,e, c;
void bfs(vector<ll> us) {
    s=e=0; c++;
    for(ll u: us) vis[u]=c, q[e++]=u, d[u]=0, p[u]=u;
    while(s<e) {
        ll u=q[s++];
        for(auto v: ady[u]) if(vis[v]<c)
            vis[v]=c, q[e++]=v, d[v]=d[u]+1, p[v]=u;
    }
}
