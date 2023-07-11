#include <bits/stdc++.h>

#define fi first
#define se second
using namespace std;

int T, n, pos;
double pi, Ox, Oy, w, h, phi;
double S, sum;
int deq[50000];
vector <pair<double, double>> Map;

bool Clockwise(double x1, double y1, double x2, double y2)
{
    return ((x1 * y2) - (x2 * y1)) <= 0;
}

void ConvexHull()
{
    deq[1] = 0;
    deq[2] = 1;
    pos = 2;
    int i = 2;
    while (i <= n - 1) {
        while (pos >= 2 && !Clockwise(Map[deq[pos]].fi - Map[deq[pos-1]].fi, Map[deq[pos]].se - Map[deq[pos-1]].se, Map[i].fi - Map[deq[pos]].fi, Map[i].se - Map[deq[pos]].se))
            pos--;
        deq[++pos] = i;
        i++;
    }
    int temp = pos;
    i = n - 2;
    while (i >= 0)
    {
        while (pos > temp && !Clockwise(Map[deq[pos]].fi - Map[deq[pos-1]].fi, Map[deq[pos]].se - Map[deq[pos-1]].se, Map[i].fi - Map[deq[pos]].fi, Map[i].se - Map[deq[pos]].se))
            pos--;
        deq[++pos] = i;
        i--;
    }
}

void RectangleCenter()
{
    w /= 2.0;
    h /= 2.0;
    Map.push_back({Ox + w, Oy + h});
    Map.push_back({Ox - w, Oy - h});
    Map.push_back({Ox - w, Oy + h});
    Map.push_back({Ox + w, Oy - h});
}

void Rectangle()
{
    double q1, q2, p1, p2;
    q1 = h * sin(phi);
    q2 = w * cos(phi);
    p1 = h * cos(phi);
    p2 = w * sin(phi);

    double xA = Ox + (q1 + q2) / 2 - q2;
    double yA = Oy + (p1 + p2) / 2;
    double xB = Ox - (q1 + q2) / 2;
    double yB = Oy + (p1 + p2) / 2 - p1;

    Map.push_back({xA, yA});
    Map.push_back({xB, yB});
    Map.push_back({Ox * 2.0 - xA, Oy * 2.0 - yA});
    Map.push_back({Ox * 2.0 - xB, Oy * 2.0 - yB});
}

void calculateArea()
{
    sum = 0.0;
    for(int i = 1; i <= pos-1; i++) {
        sum += (Map[deq[i]].fi * Map[deq[i+1]].se - Map[deq[i]].se * Map[deq[i+1]].fi);
    }
    sum = fabs(sum);
    sum /= 2.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pi = acos(-1);
    cin >> T;
    while (T--)
    {
        Map.clear();
        S = 0.0;
        cin >> n;
        while (n--) {
            cin >> Ox >> Oy >> w >> h >> phi;
            S += w * h;
            if (phi == 0.0) {
                RectangleCenter();
                continue;
            }
            if (phi == 90.0) {
                swap(w, h);
                RectangleCenter();
                continue;
            }
            if (phi < 0) {
                phi = abs(phi);
                phi = 90.0 - phi;
                swap(w, h);
            }
            phi = phi / 180.0 * pi;
            Rectangle();
        }
        sort(Map.begin(), Map.end());
        n = unique(Map.begin(), Map.end()) - Map.begin();
        ConvexHull();
        calculateArea();
        cout << fixed << setprecision(2) << S * 100.0 / sum << '\n';
    }
}