struct point {
    double x, y;
    return dis2 (point p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};
struct circle{
    point c;
    double r;
    circle() {}
    circle(point _p, int _r) {
        c = _p, r = _r;
    }
    double getArea() {
        return r * r * acos(-1.0);
    }
    bool inCircle(point p) {
        return c.dis2(p) <= r * r;
    }
};
