struct Tarjan {
	Graph g;
	vector<ll> low, num, art;
	ll N,T=1;
	Tarjan(const Graph &_g) {
		g = _g;
		N = g.size();
		low.resize(N);
		num.resize(N);
		art.resize(N);
		rep(i,0,N) if(!num[i]) {
			dfs(i,-1);
			CC++;
		}
	}
	void dfs(ll x, ll p) {
		num[x] = low[x] = T++;
		ll child_in_tree = 0;
		for(ll y: g[x]) if(y!=p) {
			if(!num[y]) {
				child_in_tree++;
				dfs(y, x);
				low[x] = min(low[x], low[y]);
				art[x] |= low[y] >= num[x];
			} else {
				low[x] = min(low[x], num[y]);
			}
		}
		if(p == -1) {
			art[x] = child_in_tree > 1;
		}
	}
};
