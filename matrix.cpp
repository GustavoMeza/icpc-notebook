struct mat {
    int r, c;
    ll val[MAXN][MAXN];

    ll* operator[] (int i) {
        return val[i];
    }
};

void mat_zeros(mat &m, int r, int c) {
    memset(&m.r, 0, sizeof(mat));
    m.r = r; m.c = c;
}

void mat_copy(mat& a, mat& b) {
    memcpy(&a.r, &b.r, sizeof(mat));
}

void mat_eye(mat &m, int n){
    mat_zeros(m, n, n);
    for (int i = 0; i < n; i++)
        m[i][i] = 1;
}

void mat_mul(mat &a, mat &b) {
    mat c;
    mat_zeros(c, a.r, b.c);

    for (int i = 0; i < c.r; i++)
        for (int k = 0; k < c.c; k++) {
            ll v = 0;
            for (int j = 0; j < a.c; j++)
                v = (v + (a[i][j] * b[j][k]) % MOD) % MOD;
            c[i][k] = v;
        }

    mat_copy(a, c);
}

void mat_exp(mat &m, ll n) {
    mat temp;
    mat_copy(temp, m);
    mat_eye(m, m.r);
    for(; n; n>>=1) {
        if(n&1) mat_mul(m, temp);
        mat_mul(temp, temp);
    }
}

