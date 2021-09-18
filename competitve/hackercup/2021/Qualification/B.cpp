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

P(int, int) solve(const int& o, const int& n, const V(string)& mat) {
    int i, j;

    int s;
    int m = INT_MAX;

    V(int) v1(n), v2(n);

    FO(i, n) {
        s = 0;
        FO(j, n) {
            if (mat[i][j] == 'O') {
                s = 0;
                break;
            }

            if (mat[i][j] == '.') {
                s++;
            }
        }
        v1[i] = s;

        if (s > 0 && s < m) m = s;
    }

    FO(j, n) {
        s = 0;
        FO(i, n) {
            if (mat[i][j] == 'O') {
                s = 0;
                break;
            }

            if (mat[i][j] == '.') {
                s++;
            }
        }
        v2[j] = s;

        if (s > 0 && s < m) m = s;
    }

    if (m == INT_MAX) return make_pair(-1, -1);

    int c = 0;
    FO(i, n) {
        if (v1[i] == m) c++;
    }

    FO(j, n) {
        if (v2[j] == m) {
            if (m > 1) c++;
            else {
                FO(i, n) {
                    if (mat[i][j] == '.') {
                        if (v1[i] == 1) break;

                        c++;
                    }
                }
            }
        }
    }

    return make_pair(m, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n;
    V(string) mat;

    P(int, int) ans;

    int o, i;
    FOA(o, 1, t + 1) {
        cin >> n;

        mat.resize(n);
        FO(i, n) {
            cin >> mat[i];
        }

        ans = solve(o, n, mat);

        cout << "Case #" << o << ": ";
        if (ans.first == -1) cout << "Impossible";
        else cout << ans.first << " " << ans.second;
        cout << "\n";
    }

    return 0;
}
