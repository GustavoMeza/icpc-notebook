#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
const int MAXN = 1e6 + 42;
 
map<char, int> to[MAXN];
int link[MAXN], que[MAXN], sz = 1, endlink[MAXN]; vector<int> leaf[MAXN];  vector<int> ans[MAXN];
void add_str(string s, int id) {
    int v = 0;
    for(char c: s) {
        if(!to[v].count(c)) to[v][c] = sz++;
        v = to[v][c];
    }
    leaf[v].push_back(id);
}
 void push_links() {
    queue<int> q({0});
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto [c,u]: to[v])
        {
            int j = link[v];
            while(j && !to[j].count(c)) j=link[j];
            if(to[j].count(c) && to[j][c]!=u) link[u] = to[j][c];
            endlink[u] = leaf[link[u]].size()>0?link[u]:endlink[link[u]];
            q.push(u);
        }
    }
}
void walk(string s) { // Dado un conjunto de patrones encuentra todas las coincidencias en una string. aka KMP con muchos patrones.
    int v=0;
    rep(i,0,s.size()) {
        char c=s[i];
        while(v && !to[v].count(c)) v=link[v];
        if(to[v].count(c)) v=to[v][c]; 
        for(int u=v;u;u=endlink[u]) for(int x: leaf[u])
            ans[x].push_back(i);
    }
}
const int inf=1e9;
string s,m[MAXN]; int q,k[MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s>>q;
    rep(i,0,q) cin>>k[i]>>m[i];
    rep(i,0,q) add_str(m[i],i);
    push_links();
    walk(s);
    rep(i,0,q) {
        int toprint=inf;
        rep(j,k[i]-1,ans[i].size()) toprint=min(toprint,ans[i][j]-ans[i][j-k[i]+1]);
        if(toprint==inf) cout<<"-1\n";
        else cout<<toprint+m[i].size()<<"\n";
    }
}
