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

int solve(const int& o, const int& n, const int& m, const V(int)& s, const V(V(int))& p) {
  int i, j;

  V(bool) v(m, false);

  M(int, int) w;
  FO(i, m) {
    w[s[i]] = 0;
  }
  FO(i, m) {
    w[s[i]]++;
  }

  int c = 0;
  FO(i, n) {
    FO(j, m) {
      auto k = w.find(p[i][j]);
      if (k != w.end()) {
        if (k->second == 1) {
          if (v[j] == false) {
            v[j] == true;
          } else {
            c++;
          }
        }
        w[p[i][j]]--;
      } else {
        if (v[j] == false) {
          v[j] == true;
        } else {
          c++;
        }
      }
    }

    w.clear();
    FO(j, m) {
      w[p[i][j]] = 0;
    }
    FO(j, m) {
      w[p[i][j]]++;
    }
  }

  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  int n, m;
  V(int) s;
  V(V(int)) p;

  int ans;

  int o, i, j;
  FOA(o, 1, t + 1) {
    cin >> n >> m;

    s.resize(n);
    FO(i, m) {
      cin >> s[i];
    }

    p.resize(n);
    FO(i, n) {
      p.resize(m);
      FO(j, m) {
        cin >> p[i][j];
      }
    }

    ans = solve(o, n, m, s, p);

    cout << "Case #" << o << ": " << ans << "\n";
  }

  return 0;
}
