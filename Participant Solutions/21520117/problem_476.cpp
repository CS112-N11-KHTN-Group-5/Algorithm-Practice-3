/// tri phan

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Point2D {
    double x, y;

    bool operator < (const Point2D &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

Point2D operator + (const Point2D &A, const Point2D &B) {
    return {A.x + B.x, A.y + B.y};
}

Point2D operator - (const Point2D &A, const Point2D &B) {
    return {A.x - B.x, A.y - B.y};
}

double cross(const Point2D &A, const Point2D &B) {
    return A.x * B.y - B.x * A.y;
}

double cross(const Point2D &A, const Point2D &B, const Point2D &C) {
    return cross(B - A, C - A);
}

bool CW(const Point2D &A, const Point2D &B, const Point2D &C) {
    return cross(A, B, C) < 0;
}

bool CCW(const Point2D &A, const Point2D &B, const Point2D &C) {
    return cross(A, B, C) > 0;
}

vector<Point2D> ConvexHull2D(vector<Point2D> &P) {
    sort(P.begin(), P.end());

    vector<int> Top, Down;
    Top.push_back(0);
    Down.push_back(0);
    int n = P.size();

    for(int i = 1; i < n; ++i) {
        if (i == n - 1 || CW(P[0], P[i], P[n - 1])) {
            while (Top.size() > 1 && !CW(P[Top[Top.size() - 2]], P[Top.back()], P[i])) Top.pop_back();
            Top.push_back(i);
        }

        if (i == n - 1 || CCW(P[0], P[i], P[n - 1])) {
            while (Down.size() > 1 && !CCW(P[Down[Down.size() - 2]], P[Down.back()], P[i])) Down.pop_back();
            Down.push_back(i);
        }
    }

    vector<Point2D> ans;
    for(int i = 0; i < (int) Down.size(); ++i) ans.push_back(P[Down[i]]);
    for(int i = Top.size() - 2; i > 0; --i) ans.push_back(P[Top[i]]);

    return ans;
}

double Area(const vector<Point2D> &P) {
    double ans = 0;
    for(int i = 1; i < (int) P.size() - 1; ++i) ans += fabs(cross(P[0], P[i], P[i + 1]));
    return ans / 2;
}

Point2D Rotate(const Point2D &mid, const Point2D &p, const double &angle) {
    Point2D vec = p - mid;
    return {mid.x + vec.x * cos(angle) + vec.y * sin(angle), mid.y - vec.x * sin(angle) + vec.y * cos(angle)};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<Point2D> P;
        double area = 0;
        for(int i = 1; i <= n; ++i) {
            double x, y, w, h, angle; cin >> x >> y >> w >> h >> angle;

            area += w * h;
            angle = angle * M_PI / 180;

            Point2D mid = {x, y};

            P.push_back(Rotate(mid, {x + w / 2, y + h / 2}, angle));
            P.push_back(Rotate(mid, {x - w / 2, y + h / 2}, angle));
            P.push_back(Rotate(mid, {x + w / 2, y - h / 2}, angle));
            P.push_back(Rotate(mid, {x - w / 2, y - h / 2}, angle));
        }

        (cout << fixed).precision(2);
        cout << area / Area(ConvexHull2D(P)) * 100 << '\n';
    }

    return 0;
}