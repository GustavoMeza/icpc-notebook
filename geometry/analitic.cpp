auto line_eq(point u, point v) {
    auto [x, y] = u;
    auto [x2, y2] = v;
    auto dy = y2-y, dx = x2-x;
    auto _gcd = gcd(dx, dy);
    auto b = -dx/_gcd, a = dy/_gcd;
    if(a < 0) a = -a, b = -b;
    auto c = -a*x-b*y;
    return make_tuple(a, b, c);
}
