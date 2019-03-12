const int MAXN =1e6+5;

char t[MAXN];
int p[2*MAXN];

int manacher(char *s) {
    int N = strlen(s);
    N = (N << 1) | 1;
    for (int i = 0; i < N; i++) t[i] = i & 1 ? s[i >> 1] : '|';

    int c = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (c + p[c] < i) c = i, p[c] = 0;
        p[i] = min(c + p[c] - i, p[2 * c - i]);
        while (p[i] < min(i, N - 1 - i) && t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (c + p[c] < i + p[i]) c = i;
        ans = max(ans, p[i]);
    }
    
    return ans;
