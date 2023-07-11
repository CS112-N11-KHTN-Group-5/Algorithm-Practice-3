#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n;
const ld eps = 1e-12;
const ld PI = acos(-1);

struct point
{
    ld x,y;

    point operator - (point const &T)
    {
        point res;
        res.x = x - T.x;
        res.y = y - T.y;
        return res;
    }

    point operator + (point const &T)
    {
        point res;
        res.x = x + T.x;
        res.y = y + T.y;
        return res;
    }

    ld dist() {return sqrt(x*x + y*y);}
    bool operator < (point const &T) const
    {
        return x < T.x || (x == T.x && y < T.y);
    }
};


vector <point> p;

ld area(vector <point> &p)
{
    ld res = 0;
    int n = p.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        res += (p[i].x-p[j].x)*(p[i].y + p[j].y);
    }
    return res;
}

ld cosine(point a,point b)
{
    return (a.x*b.x + a.y*b.y)/(a.dist()*b.dist());
}

ld theta, x, y, w, h, sum, total;

void rotatevec(point &t, ld rad)
{
    point newvec;
    newvec.x = t.x * cos(rad) + t.y * sin(rad);
    newvec.y = t.y * cos(rad) - t.x * sin(rad);
    t = newvec;
}

void addpoint()
{
    ld rad = theta/180.0*PI;
    point v1;
    point v2;
    point ctr;
    ctr.x = x;
    ctr.y = y;
    v1.x = w/2;
    v1.y = h/2;
    v2.x = -w/2;
    v2.y = h/2;

    rotatevec(v1,rad);
    rotatevec(v2,rad);

    p.push_back(ctr + v1);
    p.push_back(ctr - v1);
    p.push_back(ctr + v2);
    p.push_back(ctr - v2);
}

void inp()
{
    sum = total = 0;
    p.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> w >> h >> theta;
        sum += w*h;
        addpoint();
    }
}

ld cw(point a, point b, point c)
{
    return {(b.x - a.x)*(a.y + b.y)+
            (c.x - b.x)*(b.y + c.y)+
            (a.x - c.x)*(c.y + a.y)};
}

void proc()
{
    sort(p.begin(),p.end());
    vector <point> hull;
    vector <point> upp;
    vector <point> low;
    hull.clear();

    n = p.size();
    for (point t:p)
    {
        /// upper hull
        while (upp.size() > 1 && cw(upp[upp.size()-2], upp[upp.size()-1], t) <= 0) upp.pop_back();
        upp.push_back(t);

        ///lower hull
        while (low.size() > 1 && cw(low[low.size()-2], low[low.size()-1], t) >= 0) low.pop_back();
        low.push_back(t);
    }

    hull = low;
    for (int i = upp.size()-2; i > 0; i--)
        hull.push_back(upp[i]);

    ld hullarea = area(hull)/2.0;
    ld res = sum/hullarea;
    res = res*100.0;
    cout << fixed << setprecision(2) << res << '\n';
}

void multitest()
{
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        proc();
    }
}


int main()
{
    //freopen("file.inp","r",stdin);
    multitest();
    return 0;
}