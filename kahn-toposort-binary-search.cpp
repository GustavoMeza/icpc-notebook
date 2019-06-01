#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < n; i++)

typedef vector<int> vi;
typedef long long ll;

// FFFFFFTTTTTTT
// regresa el ultimo F y el primer T
// asume que f(lo) = F y f(hi) = T, nunca evalua en estos puntos.
// usar valores imposibles para lo y hi
tuple<int, int> bsearch(int lo, int hi, bool f(int)) {
    while(hi-lo>1) {
        int mid = lo + (hi-lo)/2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    return make_tuple(lo, hi);
}

// modificacion al toposort de kahn
bool unique_toposort(vector<vi> &g) {
    int n = g.size();
    vi indeg(n);
    forn(u, n) {
        for(auto v: g[u]) {
            indeg[v]++;
        }
    }
    queue<int> q;
    forn(v, n) {
        if(indeg[v] == 0) {
            q.emplace(v);
        }
    }
    while(!q.empty()) {
        if(q.size() > 1) return false;
        int u = q.front(); q.pop();
        for(auto v: g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    return true;
}


int n, m;
vector<tuple<int,int> > battle;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    forn(i, m) {
        int a, b;
        cin>>a>>b;
        battle.emplace_back(a, b);
    }
    auto [ignore, ans] = bsearch(0, m+1, [](int x){
        vector<vi> g(n);
        forn(i, x) {
            auto [u, v] = battle[i];
            g[u-1].emplace_back(v-1);
        }
        return unique_toposort(g);
    });
    if(ans <= m) {
        cout<<ans<<"\n";
    } else {
        cout<<"-1\n";
    }
}
