void build_st() {
    for(int i = 0; i < N; i++) st[i+N]=A[i];
    for(int i = N-1; i >= 1; i--) st[i] = st[i<<1]+st[i<<1|1];
}

// Importante: l incluido, r excluido
int query_st(int l, int r) {
    int ans = 0;
    for(l+=N,r+=N; l<r; l>>=1,r>>=1) {
        if(l&1) ans+=st[l++];
        if(r&1) ans+=st[--r];
    }
    return ans;
}

int update_st(int p, int v) {
    for(st[p+=N]=v; p>1; p>>=1) st[p>>1] = st[p]+st[p^1];
}
