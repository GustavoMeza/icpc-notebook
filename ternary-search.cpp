const double eps = 1e-9;

// necesita una función double f(double), la función a minimizar.
double ternary_search(double L, double R){
    while (abs(R-L)>eps){
        double a=(L+L+R)/3.0;
        double b=(L+R+R)/3.0;
        if (f(a)-f(b)>=-eps) L=a;
        if (f(b)-f(a)>=-eps) R=b;
    }
    return L;
}
