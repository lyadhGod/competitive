#include<bits/stdc++.h>
using namespace std;
#define FO(i, n) for(i = 0; i < n; i++)
#define FOA(i, a, n) for(i = a; i < n; i++)
#define FOK(i, n, k) for(i = 0; i < n; i += k)
#define FOAK(i, a, n, k) for(i = a; i < n; i += k)
#define RFO(i, n) for(i = n - 1; i >= 0; i--)
#define RFOA(i, n, a) for(i = n - 1; i >= a; i--)
#define RFOK(i, n, k) for(i = n - 1; i >= 0; i -= k)
#define RFOAK(i, n, a, k) for(i = n - 1; i >= a; i -= k)
#define IT(itr, x) for(itr = x.begin(); itr != x.end(); itr++)
#define RIT(itr, x) for(itr = --x.end(); itr != --x.begin(); itr--)
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
    template<typename T> void seq(string label, forward_list<T> &var) {
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

void solve(int &z, Debug &deb) {
    int i, j, k;

    
}

int main() {
    cout << "compiled...\n\n";

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Debug deb;

    int t;
    cin >> t;  

    int z;
    FOA(z, 1, t + 1) {
        solve(z, deb);
    }

    return 0;
}