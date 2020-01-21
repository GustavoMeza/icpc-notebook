ll d[maxn], vis[maxn], q[maxn], s,e, c;
void bfs(ll u) {
    d[u]=s=e=0, vis[u]=++c, q[e++]=u;
    while(s<e) {
        u=q[s++];
        for(auto v: ady[u]) if(vis[v]<c)
            d[v]=d[u]+1, vis[v]=c, q[e++]=v;
    }
}
