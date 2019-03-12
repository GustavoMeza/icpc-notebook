// FUNCIONES EN UN NÚMERO

// por cada divisor de n, llama a f(divisor)
// O(sqrt(n))
void foreach_div(int n, void f(int)) {
    for(int d = 1; d*d<=n; d++)
        if(n%d == 0) {
            f(d);
            if(d != n/d) f(n/d);
        }
}

// ejemplo: suma de divisores de un número
ll sum_div(int n) {
    ll ans = 0;
    foreach_divisor(n, *[ans](int d) { ans+=d; });
    return ans;
}

// por cada factor primo de n, llama a f(primo, potencia)
// O(sqrt(n))
void foreach_pf(int n, void f(int, int)) { 
    for(int d=2; d*d<=n; d++)
        if(n%d == 0) {
            int a = 0;
            while(n%d==0) n/=d, a++;
            f(d, a);
        }
    if(n > 1) f(n, 1);
}

// ejemplo: calcular ͬφ(n)
int phi(int n) {
    int ans = n;
    foreach_pf(n, *[ans](int p, int a){ ans-=ans/p; });
    return ans;
}

// FUNCIONES EN UN RANGO DE NÚMEROS
// la criba itera sobre las parejas (i,j) ∊ [0, n) tal que i|j
// O(n log(n))

// ejemplo: encontrar primo en un rango
bool p[MAXN];
void sieve(int  n) {
    for(int i=0; i<n; i++) p[i] = true;
    p[0]=p[1]=false;
    for(int i=2; i<n; i++)
        for(int j=2*i; j<n; j+=i)
            p[j] = false;
}

// ejemplo: calcular numero de divisores en un rango
int num_div[MAXN];
void sieve_num_div(int  n) {
    for(int i=0; i<n; i++) num_div[i] = 0;
    num_div[0]=INF;
    for(int i=1; i<n; i++)
        for(int j=i; j<n; j+=i)
            num_div[i]++;
}

// ejemplo: calcular φ(n) en un rango
int phi[MAXN];
void sieve_phi(int n) {
    for(int i=0; i<n; i++) phi[i] = i;
    for(int i=2; i<n; i++)
        if(phi[i] == i)
            for(int j=i; j<n; j+=i)
                phi[j] -= phi[j]/i;
}
