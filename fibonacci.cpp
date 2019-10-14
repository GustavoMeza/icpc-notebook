//Using matrix.cpp

long long Fib(long long n){
    if (n==0) return 0;
    mat fib;
    mat_zeros(fib, 2, 2);
    fib[0][0]=1;
    fib[0][1]=1;
    fib[1][0]=1;
    mat_exp(fib,n-1);
    return fib[0][0];
}

// Matrices

long long fib(long long n)
{
    long long F[2][2] = {{1,1},{1,0}};
    if (n == 0) return 0;
    power(F, n-1);
    return F[0][0];
}

// Para semillas F0=a y F1=b se usa return (a*F[1][1]+b*F[1][0])%mod y el if (n==0) return a;

void power(long long F[2][2], long long n)
{
    if( n == 0 || n == 1) return;
    long long M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F, F);
    if (n%2 != 0) multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2])
{
    long long x = (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod;
    long long y = (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod;
    long long z = (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod;
    long long w = (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}


