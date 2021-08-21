#include<bits/stdc++.h>

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
#define ISCMP(t) set<t, cmp>::iterator
#define IMS(t) multiset<t>::iterator
#define IMSCMP(t) multiset<t, cmp>::iterator
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

// `Input` is a class to deal with fast integer inputting
class Input {
  public:
    // TOTAL TIME: O(M) 
    // TOTAL SPACE: O(1) 
    // `fast_inp_int` inputs int value into num
    void fast_inp_int(int& num, const char& delim = ' ') {
      bool negative = false;
      int c;

      c = getchar();
      while (c == delim) {
          c = getchar();
      };
      if (c == '-') {
          negative = true;
          c = getchar();
      }

      num = 0;
      for (; (c > 47 && c < 58); c = getchar()) {
          num = (num << 3) + (num << 1) + (c - 48);
      }

      if (negative) {
          num *= -1;
      }
    }

    // TOTAL TIME: O(M) 
    // TOTAL SPACE: O(1) 
    // `fast_inp_long_long` inputs long long value into num
    void fast_inp_long_long(long long& num, const char& delim = ' ') {
      bool negative = false;
      register int c;

      c = getchar();
      while (c == delim) {
          c = getchar();
      };
      if (c == '-') {
          negative = true;
          c = getchar();
      }

      num = 0LL;
      for (; (c > 47 && c < 58); c = getchar()) {
          num = (num << 3) + (num << 1) + (c - 48);
      }

      if (negative) {
          num *= -1;
      }
    }

    // TOTAL TIME: O(NM) 
    // TOTAL SPACE: O(N) 
    // `fast_inp_vector_int` inputs int vector into vect
    void fast_inp_vector_int(vector<int>& vect, const char& delim = ' ') {
      int n = vect.size();

      int i;
      for (i = 0; i < n; i++) {
        fast_inp_int(vect[i], delim);
      }
    }

    // TOTAL TIME: O(NM) 
    // TOTAL SPACE: O(N) 
    // `fast_inp_vector_long_long` inputs long long vector into vect
    void fast_inp_vector_long_long(vector<long long>& vect, const char& delim = ' ') {
      int n = vect.size();

      int i;
      for (i = 0; i < n; i++) {
        fast_inp_long_long(vect[i], delim);
      }
    }
};

void solve(const Input& input, const int& o) {
    int i, j, k, x, y, z;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input input;

    int t;
    input.fast_inp_int(t);  

    int o;
    FOA(o, 1, t + 1) {
        solve(input, o);
    }

    return 0;
}
