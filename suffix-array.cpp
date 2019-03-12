const int MAXN = 1e5 + 5;

int N, L;
char s[MAXN];
int SA[MAXN], pos[20][MAXN];
iii v[MAXN];

void build_SA() {
    for(int i = 0; i <= N; i++) pos[0][i] = s[i];
    for(int p = L = 1; p <= N; L++, p<<=1) {
        for(int j = 0; j <= N; j++) v[j] = iii(ii(pos[L-1][j], pos[L-1][min(j+p, N)]), j);
        sort(v, v+N+1);
        for(int j = 0; j <= N; j++) pos[L][v[j].second] = j;
    }
    L--;
    for(int i = 0; i <= N; i++) SA[pos[L][i]] = i;
}

int lcp(int x, int y) {
    int ans = 0;
    for(int i = L-1, p = 1<<(L-2); i >= 0; i--, p>>=1)
        if(pos[i][x] == pos[i][y])
            ans+=p, x+=p, y+=p;
    return ans;
}

int main() {
    scanf("%s", s);
    N = strlen(s);
    build_SA();
    int ans;
    for(int i = 1, prev = 0; i <= N; i++) {
        int pref = lcp(i, i-1);
        if(prev < pref) ans += pref - prev;
        prev = pref;
    }
    printf("%d\n", ans);
}
