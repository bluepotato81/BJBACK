#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


struct Point {
    long long x, y;
};

vector<Point> points;
vector<Point> hull;

Point pivot;

long long crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

long long distanceSquared(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
    long long cross = crossProduct(pivot, p1, p2);
    if (cross == 0)
        return distanceSquared(pivot, p1) < distanceSquared(pivot, p2);
    return cross > 0;
}

Point findPivot(vector<Point>& points) {
    Point min = points[0];
    for (Point p : points) {
        if (p.y < min.y || (p.y == min.y && p.x < min.x))
            min = p;
    }
    return min;
}

int cou() {
    size_t k=hull.size();
    int m=2;
    for(size_t i=0; i<k-2; i++) {
        long long l=crossProduct(hull[i], hull[i+1], hull[i+2]);
        if(l!=0) {
            m++;
        }
    }
    return m;
}

vector<Point> grahamScan(vector<Point>& points) {
    if (points.size() < 3) return {};

    pivot = findPivot(points);
    sort(points.begin(), points.end(), compare);

    vector<Point> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);

    for (int i = 3; i < points.size(); i++) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++) {
        long long a,b;
        scanf("%lld %lld", &a, &b);
        points.push_back({a,b});
    }



    hull = grahamScan(points);

    cout << cou() << endl;

    return 0;
}
