int N;
vector<vi> ady;

vi color;
bool bip_dfs(int n, int c) {
    if(color[n]!=-1) return color[n] == c;
    color[n] = c;
    bool ans = true;
    for(int v: ady[n])
        ans &= bip_dfs(v, 1-c);
    return ans;
}

bool bipartite() {
    color.clear();
    color.assign(N,-1);
    return bip_dfs(0,0);
}
