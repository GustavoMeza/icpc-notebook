stack<int> nodos;
vector<int> ts;
bool visited[500010];

void dfs(int current){
    visited[current] = true;
    nodos.push(current);

    for (int n : ady[current]) {
        if (!visited[n]){
            dfs(n);
        }
    }
    ts.push_back(nodos.top());
    nodos.pop();
}

void topological_sort(){
    memset(visited, 0, sizeof visited);
    ts.clear();
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ts.begin(), ts.end());
}
