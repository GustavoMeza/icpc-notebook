#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;  // tamaño del arreglo
int A[N];
int st[2 * N];

void build_st() {
    for(int i=0;i<N;i++) st[i+N]=A[i];
}

/* Para actualizar un rango y consultar un solo elemento */
/* Solo funciona para operaciones conmutativas */

// importante: l incluido, r excluido
void update_st(int l, int r, int v) {
  for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
    if (l&1) st[l++]+=v;
    if (r&1) st[--r]+=v;
  }
}

int query_st(int p) {
  int res=0;
  for (p+=N;p>0;p>>=1) res+=st[p];
  return res;
}

/* Cuando queremos recorrer el arreglo completo, mandamos todas
   las actualizaciones pendientes */
void push() {
  for (int i=1;i<N;++i) {
    st[i<<1]+=st[i];
    st[i<<1|1]+=st[i];
    st[i]=0;
  }
}
