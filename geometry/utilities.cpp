// cambiar a double si es necesario
struct point {
    ll x, y;
    point(ll x=0, ll y=0): x(x), y(y) {}
    point operator +(point q) {return point(x+q.x, y+q.y);}
    point operator *(ll k) {return point(x*k, y*k);}
    point operator -(point q) {return (*this)+q*(-1);}
};

enum orientation {
    LEFT, RIGHT, COL
};

typedef point vec;
typedef vector<point> poly;

// Vector functions

// Norm of a vector
double norm(vec v) {
    return hypot(v.y, v.x);
}

// Cross product
ll cross(vec a, vec b) {
    return a.x*b.y-a.y*b.x;
}

// Dot product
ll dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}

// parallel component of u onto v
double par_comp(vec u, vec v) {
    return dot(u, v) / norm(v);
}

// perpendicular component of u onto v
double perp_comp(vec u, vec v) {
    return cross(u, v) / norm(v);
}

// b está izq o der de a?
auto turn(vec a, vec b) {
    double area = cross(a, b);
    return area ? area > 0 ? LEFT : RIGHT : COL;
}

// Point functions

// distance from a to b
double dist(point a, point b) {
    return norm(b-a);
}

// a -> b -> c es un giro izq o der
orientation turn(point a, point b, point c) {
    return turn(b-a, c-b);
}

// altura desde c hasta AB
double dist(point a, point b, point c) {
    return abs(perp_comp(c-a, b-a));
}

// ¿lineas a-b y c-d se intersectan?
// asume a!=b y c!=d en cuyo caso es indeterminado
bool line_intersect(point a, point b, point c, point d) {
    return cross(b-a, d-c) != 0;
}

// Obtiene el punto de interseccion de las rectas a-b y c-d
// asume a!=b, c!=d y que se intersectan
point line_intersection(point a, point b, point c, point d) {
    return a + (b-a)*cross(c-a, d-c)/cross(b-a, d-c);
}
