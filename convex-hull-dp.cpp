typedef pair<long long, long long> ii;

const int MAXN = 1e6 + 5;

ii ch[MAXN];
int M, p;

bool eat(ii l3, ii l2, ii l1) {
    return  ((long double) (l1.second - l3.second)) / (l3.first - l1.first) < ((long double) (l2.second - l3.second)) / (l3.first - l2.first);
}

long long eval(long long x, ii l) {
    return l.first * x + l.second;
}

long long ch_query(long long x) {
    while(p < M - 1 && eval(x, ch[p]) > eval(x, ch[p + 1]))
        p++;
    return eval(x, ch[p]);
}

void ch_add(long long m, long long b) {
    ii l = ii(m, b);
    while(M >= 2 && eat(ch[M - 2], ch[M - 1], l))
        M--;
    ch[M++] = l;
    if(p >= M) p = M - 1;
}
