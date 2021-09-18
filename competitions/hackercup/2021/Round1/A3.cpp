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

int solve(const int& o) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n;
    char prev, curr;
    string s;
    long long m, fx, fo, i, c, j, k, p;

    int ans;

    int _mod = 1000000007;

    int o;
    FOA(o, 1, t + 1) {
        cin >> n;

        cin >> s;

        m = 0;
        fx = -1;
        fo = -1;
        for (i = 0; i < n; i++) {
            if (s[i] == '.') m += m;
            else {
                if (s[i] == 'X' && fx == -1) fx = m;
                else if(s[i] == 'O' && fo == -1) fo = m;
                m++;
            }
        }

        c = 0;
        if (fx != -1 && fo != -1) {
            prev = 'F';
            for (i = 0, j = 0; i < n; i++) {
                if (s[i] == '.') j += j;
                else if(s[i] == 'F') j++;
                else break;
            }

            c = 0;
            for (k = j; i < n; i++) {
                curr = s[i];

                if (curr == 'F') continue;

                if (curr == prev) {
                    k = j;
                    continue;
                }

                if (curr == '.') {
                    j += j;
                    if (prev == 'X') {
                        if (fo < j) {
                            p = ((long long)(fo + 1) * (long long)(m - j)) % _mod;
                        }
                    } else if (prev == 'O') {
                        if (fx < j) {
                            p = ((long long)(fx + 1) * (long long)(m - j)) % _mod;
                        }
                    }
                } else {
                    p = ((long long)(k + 1) * (long long)(m - j)) % _mod;

                    k = j;
                    prev = curr;
                }

                c = (c + p) % _mod;
            }
        }

        cout << "Case #" << o << ": " << c << "\n";
    }

    return 0;
}