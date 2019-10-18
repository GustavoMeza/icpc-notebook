// Estructura de ejemplo.
struct S {
    int value1;
    int value2;

    S(int v1, int v2) : value1(v1), value2(v2){}
    S() : value1(INT_MAX), value2(INT_MAX){}

    bool isEmpty() {
        return (value1 == INT_MAX);
    }
};

const int N = 1e3;  // limit for array size
int A[N];
S st[2 * N];

// Combinar los nodos de la manera que queramos
S combine(S ln, S rn) {
    if (ln.isEmpty()) return rn;
    if (rn.isEmpty()) return ln;

    return S(max(ln.value1, rn.value1), rn.value2);
}

/***************************************************************/
/**    Para actualizar un rango y consultar un solo elemento  **/
/***************************************************************/

// Inicializar la estructura a conveniencia.
void build_st() {
    for(int i=0;i<N;i++) st[i+N] = S(A[i], A[i]);
}

// importante: l incluido, r excluido
void update_st(int l, int r, const S& v) {
  for (l+=N,r+=N;l<r;l>>=1,r>>=1) {
    if (l&1) st[l]=combine(st[l], v), l++;
    if (r&1) --r, st[r]=combine(st[r], v); // Acomodar a conveniencia
  }
}

S query_st(int p) {
  S res=S();
  for (p+=N;p>0;p>>=1) res=combine(res, st[p]);
  return res;
}

/* Cuando queremos recorrer el arreglo completo, mandamos todas
   las actualizaciones pendientes */
void push() {
  for (int i=1;i<N;++i) {
    st[i<<1]=combine(st[i<<1], st[i]); // Orden que mas convenga
    st[i<<1|1]=combine(st[i<<1|1], st[i]);
    st[i]=S();
  }
}

/*********************************************************/
/**       Actualizar un solo valor y consultar rango    **/
/*********************************************************/

// Inicializar la estructura a conveniencia.
void build_st() {
    for(int i=0;i<N;i++) st[i+N]=S(A[i],A[i]);
    for(int i=N-1;i>=1;i--) st[i]=combine(st[i<<1],st[i<<1|1]);
}

void update_st(int p, const S& v) {
  for (st[p += N]=v;p>>=1;) st[p]=combine(st[p<<1],st[p<<1|1]);
}

S query_st(int l, int r) {
  S resl = S();
  S resr = S();
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, st[l++]);
    if (r&1) resr = combine(st[--r], resr);
  }
  return combine(resl, resr);
}
