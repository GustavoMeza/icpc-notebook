const ll MOD = (5<<25) + 1;
const int MAXM = (1<<21) + 5;

void FFT(ll *P, int n, ll w) {
    if(n == 1) return;
    ll Q[2][n>>1];
    for(int i = 0; i < n; i++) Q[i&1][i>>1]=P[i];
    FFT(Q[0], n>>1, (w*w) % MOD);
    FFT(Q[1], n>>1, (w*w) % MOD);
    ll wi = 1;
    for(int i = 0; i < n>>1; i++) {
        P[i] = (Q[0][i] + wi*Q[1][i]) % MOD;
        P[i+(n>>1)] = (Q[0][i] - wi*Q[1][i]) % MOD;
        wi = (wi * w) % MOD;
    }
}

void poly_mult(ll *A, ll *B, int &M) {
    while(M != (M&-M)) M += M&-M;
    M<<=1;
    ll w = 243, winv=114609789, minv = (1-MOD)/M;
    for(int i = 1; i*M < (1<<25); i<<=1)
        w = (w*w) % MOD, winv = (winv * winv) % MOD;
    FFT(A, M, w);
    FFT(B, M, w);
    for(int i = 0; i < M; i++) A[i] = (A[i]*B[i]) % MOD;
    FFT(A, M, winv);
    for(int i = 0; i < M; i++) {
        A[i] = (A[i] * minv) % MOD;
        if(A[i] < 0) A[i] += MOD;
    }
}
