const int MAXN = 1e5+5;

int LN, D[MAXN], P[17][MAXN];
vector<vi> ady;

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

int dfs(int n, int p, int d) {
    P[0][n] = p;
    D[n] = d;
    for(int i = 0; i < ady[n].size(); i++)
        if(ady[n][i] != p)
            dfs(ady[n][i], n, d+1);
}

int N, a, b;

int main() {
    scanf("%d", &N);
    ady.assign(N, vi());
    for(int i = 1; i < N; i++) {
        scanf("%d%d", &a, &b);
        ady[a-1].push_back(b-1);
        ady[b-1].push_back(a-1);
    }
    dfs(0, 0, 0);
    for(int i = 1; i < N; i<<=1) LN++;
    for(int i = 1; i < LN; i++)
        for(int n = 0; n < N; n++)
            if(P[i-1][n] != -1)
                P[i][n] = P[i-1][P[i-1][n]];
}
