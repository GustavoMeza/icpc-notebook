int build_st(int n, int L, int R) {
    if(L == R) return st[n] = -1;
    int mid = (L+R)/2;
    int a = build_st(n<<1, L, mid);
    int b = build_st(n<<1|1, mid+1, R);
    return st[n] = max(a, b);
}

int update_st(int n, int L, int R, int p, int v) {
    if(L == R) return st[n] = v;
    int mid = (L+R)/2;
    int a = st[n<<1], b = st[n<<1|1];
    if(p <= mid) a = update_st(n<<1, L, mid, p, v);
    else b = update_st(n<<1|1, mid+1, R, p, v);
    return st[n] = max(a, b);
}

int find_st(int n, int L, int R, int v) {
    if(L == R) return L;
    int mid = (L+R)/2;
    if(st[n<<1] > v) return find_st(n<<1, L, mid, v);
    return find_st(n<<1|1, mid+1, R, v);
}

int solve_st(int n, int L, int R, int tL, int v) {
    if(L == R) return st[n] > v ? L : -1;
    int mid = (L+R)/2;
    int a;
    if(tL <= mid) {
        a = solve_st(n<<1, L, mid, tL, v);
        if(a<0 && st[n<<1|1] > v) return find_st(n<<1|1, mid+1, R, v);
    } else a = solve_st(n<<1|1, mid+1, R, tL, v);
    return a;
}
