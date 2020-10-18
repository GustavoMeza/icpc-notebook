#include<vector>
#include<stack>
using namespace std;
void tarjan(int cur, int prev, vector<vector<int> > &_scc,vector<int> * _adj, stack<int> & _st, int *lo, int *hi,bool * inStack,bool * vis, int &dt) {
    lo[cur]=hi[cur]=dt++;
    _st.push(cur);
    vis[cur]=true;
    inStack[cur]=true;
    for (int ni:_adj[cur]) {
        if (vis[ni]) {
            if (inStack[ni])
                hi[cur]=min(hi[cur], lo[ni]);
        } else {
            tarjan(ni, cur,_scc,_adj,_st,lo,hi,inStack,vis, dt);
            hi[cur]=min(hi[cur], hi[ni]);
        }
    }
    if (lo[cur]==hi[cur]) {
    vector<int> next_cc;
        while (_st.empty()==false && _st.top()!=cur) {
            next_cc.push_back(_st.top());
            inStack[_st.top()]=false;
            _st.pop();
        }
        inStack[cur]=false;
        _st.pop();
        next_cc.push_back(cur);
        _scc.push_back(next_cc);
    }
}
//Recibe N , lista de adyacencia, y un output por referencia, devuelve un vector con las SCC.
void scc(int N, vector<int> *adj,vector<vector<int> > & output) {

    stack<int> st;
    int * lo = new int[N];
    int * hi = new int[N];
    bool* vis= new bool[N];
    bool* inStack= new bool[N];
    int cont=0;
    for (int i =0; i< N; i++) inStack[i]=vis[i]=false;
    for (int i =0; i <N; i++) {
     if (!vis[i]){
        tarjan(i,i,output, adj, st, lo,hi,inStack, vis, cont);
     }
    }
    delete[] lo;
    delete[] hi;
    delete[] vis;
    delete[] inStack;
}
int main() {
    return 0;
}
