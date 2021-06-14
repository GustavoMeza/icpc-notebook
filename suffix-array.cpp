const int MAXN = 5e5 + 5;
int N, L, SA[MAXN], pos[20][MAXN];
array<int,3> v[MAXN];

void build_SA(string s) {
    N=s.size();
    rep(i,0,N+1) pos[0][i] = s[i];
    for(int p = L = 1; p <= N; L++, p<<=1) {
        rep(j,0,N+1) v[j] = {pos[L-1][j], pos[L-1][min(j+p, N)], j};
        sort(v, v+N+1);
        rep(j,0,N+1) pos[L][v[j][2]] = j>0&&v[j][0]==v[j-1][0]&&v[j][1]==v[j-1][1]?pos[L][v[j-1][2]]:j;
    }
    L--;
    rep(i,0,N+1) SA[pos[L][i]] = i;
}

int lcp(int x, int y) {
    int ans = 0;
    for(int i = L-1, p = 1<<i; i >= 0; i--, p>>=1)
        if(pos[i][x] == pos[i][y])
            ans+=p, x+=p, y+=p;
    return ans;
}
