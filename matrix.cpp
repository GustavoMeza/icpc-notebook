struct mat {
    ll val[maxn][maxn];
    mat(){ memset(val, 0, sizeof(val)); }
    ll* operator[] (ll i) {return val[i];}
} ady;
void mat_mul(mat &a, mat &b) {
    mat c;
    rep(i,0,n) rep(j,0,n) rep(k,0,n)
        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(&a,&c,sizeof a);
}
void mat_exp(mat &a, ll x) {
    mat b; rep(i,0,n) b[i][i]=1;
    for(;x;x/=2,mat_mul(a,a)) if(x&1) mat_mul(b,a);
    memcpy(&a,&b,sizeof a);
}
