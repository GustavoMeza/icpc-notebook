const ll maxm=2e6+5;
ll cnt[maxm],m=1;
map<char,ll> t[maxm];
void add(string s) {
    ll v=0;
    for(char c: s) {
        cnt[v]++;
        if(!t[v].count(c)) t[v][c]=m++;
        v=t[v][c];
    }
}
void clean() {
    rep(i,0,m) {
        t[i].clear();
        cnt[i]=0;
    }
    m=1;
}
