#include <bits/stdc++.h>

#define FO(i, n) for(i = 0; i < n; i++)
#define FOA(i, a, n) for(i = a; i < n; i++)
#define FOK(i, n, k) for(i = 0; i < n; i += k)
#define FOAK(i, a, n, k) for(i = a; i < n; i += k)
#define RFO(i, n) for(i = n - 1; i >= 0; i--)
#define RFOA(i, a, n) for(i = n - 1; i >= a; i--)
#define RFOK(i, n, k) for(i = n - 1; i >= 0; i -= k)
#define RFOAK(i, a, n, k) for(i = n - 1; i >= a; i -= k)
#define IT(itr, x) for(itr = x.begin(); itr != x.end(); itr++)
#define ITR(itr, g, h) for(itr = g; itr != h; itr++)
#define RIT(itr, x) for(itr = --x.end(); itr != --x.begin(); itr--)
#define RITR(itr, g, h) for(itr = --h; itr != --g; itr--)
#define ALL(x) x.begin(), x.end()
#define PF(p) p.first
#define PS(p) p.second
#define PPF(p) p->first
#define PPS(p) p->second
#define P(t1, t2) pair<t1, t2>
#define V(t) vector<t>
#define L(t) list<t>
#define FL(t) forward_list<t>
#define S(t) set<t>
#define SCMP(t) set<t, cmp>
#define MS(t) multiset<t>
#define MSCMP(t) multiset<t, cmp>
#define M(k, v) map<k, v>
#define MCMP(k, v, cmp) map<k, v, cmp>
#define MM(k, v) multimap<k, v>
#define MMCMP(k, v, cmp) multimap<k, v, cmp>
#define US(t) unordered_set<t>
#define USCMP(t, cmp) unordered_set<t, cmp>
#define UMS(t) unordered_multiset<t>
#define UMSCMP(t, cmp) unordered_multiset<t, cmp>
#define UM(k, v) unordered_map<k, v>
#define UMCMP(k, v, cmp) unordered_map<k, v, cmp>
#define UMM(k, v) unordered_multimap<k, v>
#define UMMCMP(k, v, cmp) unordered_multimap<k, v, cmp>
#define IV(t) vector<t>::iterator
#define IL(t) list<t>::iterator
#define IFL(t) forward_list<t>::iterator
#define IS(t) set<t>::iterator
#define ISCMP(t, cmp) set<t, cmp>::iterator
#define IMS(t) multiset<t>::iterator
#define IMSCMP(t, cmp) multiset<t, cmp>::iterator
#define IM(k, v) map<k, v>::iterator
#define IMCMP(k, v, cmp) map<k, v, cmp>::iterator
#define IMM(k, v) multimap<k, v>::iterator
#define IMMCMP(k, v, cmp) multimap<k, v, cmp>::iterator
#define IUS(t) unordered_set<t>::iterator
#define IUSCMP(t, cmp) unordered_set<t, cmp>::iterator
#define IUMS(t) unordered_multiset<t>::iterator
#define IUMSCMP(t, cmp) unordered_multiset<t, cmp>::iterator
#define IUM(k, v) unordered_map<k, v>::iterator
#define IUMCMP(k, v, cmp) unordered_map<k, v, cmp>::iterator
#define IUMM(k, v) unordered_multimap<k, v>::iterator
#define IUMMCMP(k, v, cmp) unordered_multimap<k, v, cmp>::iterator
#define ST(t) stack<t>
#define Q(t) queue<t>
#define DQ(t) deque<t>
#define PQ(t) priority_queue<t>
#define PQCMP(t, cmp) priority_queue<t, vector<t>, cmp>
#define GT(t) greater<t>()
#define LT(t) less<t>()

using namespace std;

double area(const P(int, int)& p1, const P(int, int)& p2, const P(int, int)& p3) {
    int a1 = p1.first * (p2.second - p3.second);
    int a2 = p2.first * (p1.second - p3.second);
    int a3 = p3.first * (p1.second - p2.second);

    return abs((double) (a1 + a2 + a3) / 2.0);
}

double dist(const P(int, int)& p1, const P(int, int)& p2) {
    int a1 = PF(p1) - PF(p2);
    a1 *= a1;

    int a2 = PS(p1) - PS(p2);
    a2 *= a2;

    return sqrt((double) (a1 + a2));
}

string solve(const int& o, const int& n, V(P(int, int))& w, const P(int, int)& b) {
    if (n < 3) {
        return "IMPOSSIBLE";
    }

    int i, j;

    MM(double, int) d;

    double k;
    FO(i, n) {
        k = dist(w[i], b);
        d.emplace(k, i);
    }

    auto p1 = d.begin();
    auto p2 = ++d.begin();
    auto p3 = ++(++d.begin());

    double z, z1, z2, z3, zz;
    for (; p3 != d.end(); p1 = p2, p2 = p3, p3++) {
        z = area(w[PPS(p1)], w[PPS(p2)], w[PPS(p3)]);
        
        z1 = area(w[PPS(p1)], w[PPS(p2)], b);
        z2 = area(w[PPS(p2)], w[PPS(p3)], b);
        z3 = area(w[PPS(p1)], w[PPS(p3)], b);
        zz = z1 + z2 + z3;

        if (abs(z - zz) < 0.000001) {
            break;
        }
    }

    if (p3 == d.end()) {
        return "IMPOSSIBLE";
    }

    k = dist(w[PPS(p1)], w[PPS(p2)]) + dist(w[PPS(p2)], w[PPS(p3)]) + dist(w[PPS(p1)], w[PPS(p3)]);

    return to_string(k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n;
    V(P(int, int)) w;
    P(int, int) b;

    string ans;

    int o, i, e, f;
    FOA(o, 1, t + 1) {
        cin >> n;

        w.resize(n);
        FO(i, n) {
            cin >> e >> f;
            w[i] = make_pair(e, f);
        }

        cin >> e >> f;
        b = make_pair(e, f);

        ans = solve(o, n, w ,b);

        cout << "Case #" << o << ": " << ans << "\n";
    }

    return 0;
}
