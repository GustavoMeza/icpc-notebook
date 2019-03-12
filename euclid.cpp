// log n
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

// log n
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

// minima solución ax+by=d según |x|+|y| en log n
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = extgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

// minima solucion particular ax+by=c según |x|+|y|
// solucion general x0+b/d*t, y0-a/d*t
bool diophant(ll a, ll b, ll c, ll &x, ll &y) {
    ll d = extgcd(a, b, x, y);
    if(c%d != 0) return false;
    x *= c/d, y *= c/d;
    return true;
}

// solución ax=1 mod m en log m
bool inverse_mod(ll a, ll m, ll &x) {
    ll y;
    if(!diophant(a, m, 1, x, y)) return false;
    x = ((x%m)+m)%m;
    return true;
}

// Teorema chino del residuo:
// Dado un sistema de n congruencias x ≡  a_i (mod m_i)
// O no tiene solución
// O tiene una única solución x ≡ A (mod M)
// nlogn
bool chineese(ll *m, ll *a, int n, ll &A, ll &M) {
    a[0] %= m[0];
    if(n == 1) {
        A = a[0], M = m[0];
        return true;
    }
    if(!chineese(m+1, a+1, n-1, A, M)) return false;
    ll x0, y0;
    if(!diophant(M, m[0], a[0]-A, x0, y0)) return false;
    A += M*x0, M = lcm(M, m);
    A = ((A%M)+M)%M;
    return true;
}
