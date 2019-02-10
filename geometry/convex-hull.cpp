// dependencies from utilities.cpp
// point, vec, poly, orientation
// norm(vec)
// cross(vec, vec)
// turn(vec, vec)
// dist(point, point)
// turn(point, point, point)
poly convex_hull(poly P) {
   sort(P.begin(), P.end(), [](point a, point b){
        if(a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });
    point p0 = P[0];
    sort(P.begin()+1, P.end(), [p0](point a, point b) {
        auto t = turn(a, p0, b);
        return t == COL ? dist(a, p0) < dist(b, p0) : t == RIGHT;
    });
    poly ch;
    for(point p : P) {
        while(ch.size() > 1 && turn(*(ch.end()-2), ch.back(), p) != LEFT)
            ch.pop_back();
        ch.push_back(p);
    }
    return ch;
}
