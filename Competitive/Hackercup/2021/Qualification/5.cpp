#include <bits/stdc++.h>

#define FO(i, n) for(i = 0; i < n; i++)
#define FOA(i, a, n) for(i = a; i < n; i++)
#define FOK(i, n, k) for(i = 0; i < n; i += k)
#define FOAK(i, a, n, k) for(i = a; i < n; i += k)
#define RFO(i, n) for(i = n - 1; i >= 0; i--)
#define RFOA(i, n, a) for(i = n - 1; i >= a; i--)
#define RFOK(i, n, k) for(i = n - 1; i >= 0; i -= k)
#define RFOAK(i, n, a, k) for(i = n - 1; i >= a; i -= k)
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

void out_unweighted_graph(const vector<vector<long long>>& value, const string& label = "") {
  if (label.size() > 0) {
    cout << label << ": ";
  }
  cout << "[\n";

  int n = value.size();

  int count, j, i;
  for (i = 0; i != n; i++) {
    cout << "    " << i << ": [ ";

    count = value[i].size();
    for (j = 0; j < count; j++) {
      cout << value[i][j] << ", ";
    }

    cout << "]\n";
  }

  cout << "]\n";
}

void decompose(const int& i, V(V(int))& g, V(long long)& w, V(bool)& v) {
    v[i] = true;

    int k, j, p, m, d;
    int n = g[i].size();
    FO(k, n) {
        j = g[i][k];

        if (v[j] == true) continue;

        decompose(j, g, w, v);

        if (g[j].size() == 2) {
            p = (g[j][0] == i) ? g[j][1] : g[j][0];

            w[p] += w[j];
            
            d = g[p].size();
            FO(m, d) {
                if (g[p][m] == j) {
                    g[p][m] = i;
                    break;
                }
            }

            g[i][k] = p;

            g[j].clear();
        }
    }
}

long long work(const int& i, const V(V(int))& g, const V(long long)& w, V(bool)& v, V(V(long long))& mat, const int& k) {
    if (v[i] == true) return 0LL;

    if (mat[i][k] > 0LL) return 0LL;

    if (k == 0) {
        mat[i][k] = w[i];
        return mat[i][k];
    }

    v[i] = true;

    int n = g[i].size();

    V(int) se(n);

    int m, j, p;
    long long q, d = 0LL;
    FO(m, k + 1) {
        FO(j, n) {
            se[j] = work(g[i][j], g, w, v, mat, m);
        }

        sort(se.begin(), se.end(), GT(long long));

        p = m;
        q = 0LL;
        FO(j, n) {
            q += se[j];
            if (j & 1 == 0) p--;
            if (q < 0) break;
        }
        q += w[i];

        mat[i][m] = max(mat[i][m], q);

        d = max(d, mat[i][m]);
    }

    return d;
}

long long solve(const int& o, const int& n, const int& k, V(long long)& w, V(V(int))& g) {    
    V(bool) v(n, false);
    decompose(0, g, w, v);

    fill(v.begin(), v.end(), false);
    V(V(long long)) mat(n, V(long long)(k + 1, 0LL));
    work(0, g, w, v, mat, k);

    return mat[0][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    long long ans;

    int n, k;
    V(long long) w;
    V(V(int)) g;

    int o, i, a, b;
    FOA(o, 1, t + 1) {
        cin >> n >> k;

        w.clear();
        w.resize(n);
        FO(i, n) {
            cin >> w[i];
        } 

        g.clear();
        g.resize(n);
        FO(i, n - 1) {
            cin >> a >> b;
            if (find(g[a - 1].begin(), g[a - 1].end(), b - 1) == g[a - 1].end()) g[a - 1].emplace_back(b - 1);
            if (find(g[b - 1].begin(), g[b - 1].end(), a - 1) == g[b - 1].end()) g[b - 1].emplace_back(a - 1);
        }

        ans = solve(o, n, k, w, g);

        cout << "Case #" << o << ": " << ans << "\n";
    }

    return 0;
}
