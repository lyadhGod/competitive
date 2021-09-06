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

// Time: O(1); Space: O(1);
long long mod_add(
  const long long& a,
  const long long& b,
  const long long& mod
) {
  long long x = a;
  if (x < 0) {
    x += mod;
  } else if (x >= mod) {
    x %= mod;
  }

  long long y = b;
  if (y < 0) {
    y += mod;
  } else if (y >= mod) {
    y %= mod;
  }

  long long res = x + y;
  if (res < 0) {
    res += mod;
  } else if (res >= mod) {
    res %= mod;
  }

  return res;
}

// Time: O(1); Space: O(1);
long long mod_sub(
  const long long& a,
  const long long& b,
  const long long& mod
) {
  long long x = a;
  if (x < 0) {
    x += mod;
  } else if (x >= mod) {
    x %= mod;
  }

  long long y = b;
  if (y < 0) {
    y += mod;
  } else if (y >= mod) {
    y %= mod;
  }

  long long res = x - y;
  if (res < 0) {
    res += mod;
  } else if (res >= mod) {
    res %= mod;
  }

  return res;
}

// Time: O(1); Space: O(1);
long long mod_mul(
  const long long& a,
  const long long& b,
  const long long& mod
) {
  long long x = a;
  if (x < 0) {
    x += mod;
  } else if (x >= mod) {
    x %= mod;
  }

  long long y = b;
  if (y < 0) {
    y += mod;
  } else if (y >= mod) {
    y %= mod;
  }

  long long res = x * y;
  if (res < 0) {
    res += mod;
  } else if (res >= mod) {
    res %= mod;
  }

  return res;
}

long long solve(const int& o, const int& n, const int& k, const int& w, const V(long long)& l, const V(long long)& h) {
    long long _mod = 1000000007LL;

    long long t;

    long long ans;

    ans = h[0] + h[0] + w + w;

    long long ov;

    int i;
    FOA(i, 1, n) {
        ov = l[i - 1] + w - l[i];

        if (ov < 0) {
            t = h[i] + h[i] + w + w;
        } else {
            t = ans - (ov + ov + h[i - 1]);
            t += abs(h[i] - h[i - 1]) + w + w + h[i];
        }

        ans = mod_mul(ans, t, _mod);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n, k, w;
    V(long long) l, h;
    long long al, bl, cl, dl;
    long long ah, bh, ch, dh;

    long long ans;

    int o, i;
    FOA(o, 1, t + 1) {
        cin >> n >> k >> w;

        l.resize(n);
        FO(i, k) {
            cin >> l[i];
        }

        cin >> al >> bl >> cl >> dl;
        FOA(i, k, n) {
            l[i] = (((al * l[i - 2]) + (bl * l[i - 1]) + cl) % dl) + 1LL;
        }

        h.resize(n);
        FO(i, k) {
            cin >> h[i];
        }

        cin >> ah >> bh >> ch >> dh;
        FOA(i, k, n) {
            h[i] = (((ah * h[i - 2]) + (bh * h[i - 1]) + ch) % dh) + 1LL;
        }

        ans = solve(o, n, k, w, l, h);

        cout << "Case #" << o << ": " << ans << "\n";
    }

    return 0;
}
