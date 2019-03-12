const int MAXN = 2e5+5;
const int MAXL = 20;

int N;
vector<vi> ady;
int L, D[MAXN], P[MAXL][MAXN];

int query_binlift(int u, int v) {
    if(D[u] > D[v]) swap(u, v);
    int diff = D[v]-D[u];
    for(int i = 0; i < L; i++)
        if(diff & (1<<i))
            v = P[i][v];
    if(u == v) return u;
    for(int i = L-1; i>=0; i--)
        if(P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    return P[0][u];
}

void build_binlift() {
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int n = q.front(); q.pop();
        for(int e : ady[n])
            if(e != P[0][n])
                q.push(e), P[0][e] = n, D[e] = D[n]+1;
    }
    for(L = 0; (1<<L) < N; L++);
    for(int i = 1; i < L; i++)
        for(int n = 0; n < N; n++)
            P[i][n] = P[i-1][P[i-1][n]];
}
