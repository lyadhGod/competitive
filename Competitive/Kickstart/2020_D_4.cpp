#include<bits/stdc++.h>
using namespace std;
#define fo(i, n) for(i = 0; i <= n; i++)
#define foa(i, a, n) for(i = a; i <= n; i++)
#define fok(i, n, k) for(i = 0; i <= n; i += k)
#define foak(i, a, n, k) for(i = a; i <= n; i += k)
#define rfo(i, n) for(i = n; i >= 0; i--)
#define rfoa(i, n, a) for(i = n; i >= a; i--)
#define rfok(i, n, k) for(i = n; i >= 0; i -= k)
#define rfoak(i, n, a, k) for(i = n; i >= a; i -= k)
#define it(itr, x) for(itr = x.begin(); itr != x.end(); itr++)
#define rit(itr, x) for(itr = --x.end(); itr != --x.begin(); itr--)
#define all(x) x.begin(), x.end()
#define pf(p) p.first
#define ps(p) p.second
#define ppf(p) p->first
#define pps(p) p->second
#define p(t1, t2) pair<t1, t2>
#define v(t) vector<t>
#define l(t) list<t>
#define m(k, v) map<k, v>
#define mcmp(k, v, cmp) map<k, v, cmp>
#define s(t) set<t>
#define scmp(t) set<t, cmp>
#define um(k, v) unordered_map<k, v>
#define umcmp(k, v, cmp) unordered_map<k, v, cmp>
#define us(t) unordered_set<t>
#define uscmp(t, cmp) unordered_set<t, cmp>
#define iv(t) vector<t>::iterator
#define il(t) list<t>::iterator
#define im(k, v) map<k, v>::iterator
#define imcmp(k, v, cmp) map<k, v, cmp>::iterator
#define is(t) set<t>::iterator
#define iscmp(t) set<t, cmp>::iterator
#define ium(k, v) unordered_map<k, v>::iterator
#define iumcmp(k, v, cmp) unordered_map<k, v, cmp>::iterator
#define ius(t) unordered_set<t>::iterator
#define iuscmp(t, cmp) unordered_set<t, cmp>::iterator
#define stack(t) stack<t>
#define queue(t) queue<t>
#define dqueue(t) deque<t>
#define pqueue(t) priority_queue<t>
#define pqueuecmp(t, cmp) priority_queue<t, vector<t>, cmp>
#define gr(t) greater<t>
#define le(t) less<t>

struct Debug {
    template<typename T> void var(string label, T &var) { 
        cout << "\ndebugging >>> " << label << ": " << var << "\n\n"; 
    }

    template<typename T, typename R> void pair(string label, pair<T, R> &var) { 
        cout << "\ndebugging >>> " << label << ": " << var.first << ", " << var.second << "\n\n"; 
    }

    template<typename T> void seq(string label, vector<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }
    template<typename T> void seq(string label, list<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }
    template<typename T> void seq(string label, set<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }
    template<typename T> void seq(string label, multiset<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }
    template<typename T> void seq(string label, unordered_set<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }
    template<typename T> void seq(string label, unordered_multiset<T> &var) {
        cout << "\ndebugging >>> " << label << ": [ ";
        if(var.size() > 0) {
            cout << *var.begin();
            for(auto iter = ++var.begin(); iter != var.end(); iter++) {
                cout << ", " << *iter;
            }
        }
        cout << " ]\n\n";
    }

    template<typename T, typename R> void assoc(string label, map<T, R> &var) {
        cout << "\ndebugging >>> " << label << ": { ";
        if(var.size() > 0) {
            cout << var.begin()->first << " => " << var.end()->second;
            for(auto iteri = ++(var.begin()); iteri != var.end(); iteri++) {
                cout << ", " << iteri->first << " => " << iteri->second;
            }
        }
        cout << " }\n\n";
    }
    template<typename T, typename R> void assoc(string label, multimap<T, R> &var) {
        cout << "\ndebugging >>> " << label << ": { ";
        if(var.size() > 0) {
            cout << var.begin()->first << " => " << var.end()->second;
            for(auto iteri = ++(var.begin()); iteri != var.end(); iteri++) {
                cout << ", " << iteri->first << " => " << iteri->second;
            }
        }
        cout << " }\n\n";
    }
    template<typename T, typename R> void assoc(string label, unordered_map<T, R> &var) {
        cout << "\ndebugging >>> " << label << ": { ";
        if(var.size() > 0) {
            cout << var.begin()->first << " => " << var.end()->second;
            for(auto iteri = ++(var.begin()); iteri != var.end(); iteri++) {
                cout << ", " << iteri->first << " => " << iteri->second;
            }
        }
        cout << " }\n\n";
    }
    template<typename T, typename R> void assoc(string label, unordered_multimap<T, R> &var) {
        cout << "\ndebugging >>> " << label << ": { ";
        if(var.size() > 0) {
            cout << var.begin()->first << " => " << var.end()->second;
            for(auto iteri = ++(var.begin()); iteri != var.end(); iteri++) {
                cout << ", " << iteri->first << " => " << iteri->second;
            }
        }
        cout << " }\n\n";
    }

    template<typename T, typename P> void graph(string label, unordered_map<T, vector<P>> &var) {
        cout << "\ndebugging >>> " << label << ": {\n";
        for(auto iteri = var.begin(); iteri != var.end(); iteri++) {
            cout << iteri->first << " => [ ";
            if(iteri->second.size() > 0) {
                cout << "(" << iteri->second.begin()->first << ", " << iteri->second.begin()->second << ")";
                for(auto iterj = ++(iteri->second.begin()); iterj != iteri->second.end(); iterj++) {
                    cout << ", (" << iterj->first << ", " << iterj->second << ")";
                }
            }
            cout << " ]\n";
        }
        cout << " }\n";
    }
};

struct L {
    struct N {
        int d;
        N   *prev, *next;
    };
    N *h, *ptr;

    L() { 
        h = ptr = nullptr; 
    }

    void add(int val) {
        if(h == nullptr) {
            h = new N();
            h->d = val;
            h->prev = h->next = nullptr;
            ptr = h;
        } else {
            N *temp = new N();
            temp->d = val;
            temp->prev = ptr;
            temp->next = nullptr;
            ptr->next = temp;
            ptr = temp;
        }
    }

    void del_prev() {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, i, j, k;

    int T;
    cin >> T;

    int ans;

    int N, Q, temp, S, K;
    v(int) vect;
    foa(t, 1, T) {
        cin >> N >> Q;

        vect.resize(3 * N);
        fo(i, vect.size()) {
            vect[i++] = i - 2;
            cin >> vect[i++];
            vect[i++] = i + 1;
        }

        while(Q--) {
            cin >> S >> K;

            while(--K) {
                
            }

            cout << "Case #" << t << ": " << S << "\n";
        }
    }

    return 0;
}
