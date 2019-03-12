const int MAXN = 5e4+5;
const int LN = ceil(log2(MAXN));

int st[MAXN<<1], N;
int sz[MAXN], H[MAXN], posB[MAXN];
vi B;
vector<vi> ady;
int D[MAXN], P[LN][MAXN];

void build_st() {
    for(int i = 0; i < N; i++) st[i+N] = B[i];
    for(int i = N-1; i; i--) st[i] = max(st[i<<1], st[(i<<1)|1]);
}

void update_st(int p, int v) {
    for(st[p+=N]=v; p>1; p>>=1) st[p>>1] = max(st[p], st[p^1]);
}

int query_st(int L, int R) {
    int ans=0;
    for(L+=N, R+=N; L != R; L>>=1, R>>=1) {
        if(L&1) ans = max(ans, st[L++]);
        if(R&1) ans = max(ans, st[--R]);
    }
    return ans;
}

void HLD(int n, int p, int head) {
    H[n] = head;
    B.push_back(0);
    posB[n] = B.size()-1;
    int maxSz = 0, heavy;
    for(auto h : ady[n])
        if(h != p && sz[h] > maxSz)
            maxSz = sz[h], heavy = h;
    if(maxSz) HLD(heavy, n, head);
    for(auto h : ady[n])
        if(h != p && h != heavy)
            HLD(h, n, h);
}

int LCA(int u, int v) {
    if(D[u] < D[v]) swap(u, v);
    int diff = D[u]-D[v];
    for(int i = 0; i < LN; i++)
        if(diff & (1<<i)) u = P[i][u];
    if(u == v) return u;
    for(int i = LN-1; i>=0; i--)
        if(P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    return P[0][u];
}

int query_up(int u, int v) {
    int ans = 0;
    for(; H[u]!=H[v]; u=P[0][H[u]])
        ans = max(ans, query_st(posB[H[u]], posB[u]+ 1));
    ans = max(ans, query_st(posB[v], posB[u]+1));
    return ans;
}

int query(int u, int v) {
    int lca = LCA(u, v);
    return max(query_up(u, lca), query_up(v, lca));
}

int dfs(int n, int p, int d) {
    P[0][n] = p;
    D[n] = d;
    sz[n] = 1;
    for(auto h : ady[n])
        if(h != p)
            sz[n] += dfs(h, n, d+1);
    return sz[n];
}

void initLCA() {
    dfs(0, 0, -1);
    for(int i = 1; i < LN; i++)
        for(int n = 0; n < N; n++)
            P[i][n] = P[i-1][n] >= 0 ? P[i-1][P[i-1][n]] : -1;
    B.clear();
    HLD(0, 0, 0);
    build_st();
}

int Q, a, b, op;

int main() {
    scanf("%d%d", &N, &Q);
    ady.assign(N, vi());
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &a, &b);
        ady[a].push_back(b);
        ady[b].push_back(a);
    }
    initLCA();
    while (Q--) {
        scanf("%d%d%d", &op, &a, &b);
        if (op == 2)
            printf("%d\n", query(a, b));
        else
            update_st(posB[a], b);
    }
}
