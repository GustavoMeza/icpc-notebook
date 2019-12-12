const int MAXN = 2e5+5;
const int L = 20;

vector<vi> ady;
int L, D[MAXN], P[L][MAXN];

int query_binlift(int u, int v) {
    if(D[u] > D[v]) swap(u, v);
    int diff = D[v]-D[u];
    forn(i, L)
        if(diff & (1<<i))
            v = P[i][v];
    for(int i = L-1; i>=0; i--)
        if(P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    return u == v ? u : P[0][u];
}

void build_binlift() {
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int n = q.front(); q.pop();
        for(int i = 1; i < L; i++)
            P[i][n] = P[i-1][P[i-1][n]];
        for(int e : ady[n])
            if(e != P[0][n])
                q.push(e), P[0][e] = n, D[e] = D[n]+1;
    }
}
