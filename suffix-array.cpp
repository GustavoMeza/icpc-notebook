// v2.1 O(N log N) mas rapido
struct SA {
	vector<vector<ll> > r;
	vector<ll> sa;
	SA(const string &s) {
		const ll N = s.size(), L = 65-__builtin_clzll(N);
		r.assign(L,vector<ll>(2*N,0));
		sa.resize(N); iota(all(sa), 0);
		sort(all(sa), [&](ll x, ll y) { return s[x] < s[y]; });
		rep(i,1,N) {
			ll x=sa[i-1], y=sa[i];
			r[0][y] = s[x] == s[y] ? r[0][x] : i;
		}
		vector<ll> cnt(N),tmp(N);
		rep(l,0,L-1) {
			ll w = 1<<l; iota(all(cnt),0);
			copy(all(sa), begin(tmp));
			rep(i,0,N) if(sa[i]>=w) tmp[cnt[r[l][sa[i]-w]]++]=sa[i]-w;
			copy(all(tmp),begin(sa));
			rep(i,1,N) {
				ll x=sa[i-1], y=sa[i];
				r[l+1][y] = r[l][x] == r[l][y] && r[l][x+w] == r[l][y+w] ? r[l+1][x] : i;
			}
		}
	}
};

// v2.0 O(N log N) mas flexible, e.g. WF 2019 G
struct SA {
	vector<vector<ll> > r;
	vector<ll> sa;
	SA(const string &s) {
		const ll N = s.size(), L = 65-__builtin_clzll(N);
		r.assign(L,vector<ll>(2*N,0));
		rep(i,0,N) r[0][i] = s[i];
		sa.resize(N); iota(all(sa), 0);
		vector<ll> cnt(max(N+1,300ll)), tmp(N);
		rep(l,0,L-1) {
			ll w = 1<<l;
			fill(all(cnt),0);
			rep(i,0,N) cnt[r[l][sa[i]+w]+1]++;
			partial_sum(all(cnt), begin(cnt));
			rep(i,0,N) tmp[cnt[r[l][sa[i]+w]]++] = sa[i];
			fill(all(cnt),0);
			rep(i,0,N) cnt[r[l][tmp[i]]+1]++;
			partial_sum(all(cnt), begin(cnt));
			rep(i,0,N) sa[cnt[r[l][tmp[i]]]++] = tmp[i];
			rep(i,1,N) {
				ll x=sa[i-1], y=sa[i];
				r[l+1][y] = r[l][x] == r[l][y] && r[l][x+w] == r[l][y+w] ? r[l+1][x] : i;
			}
		}
	}
};

// Original O(N log^2 N)
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
