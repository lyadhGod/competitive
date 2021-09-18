#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int N;
    vector<int> vect;

    SegmentTree() {
        N = 0;
        vect.resize(0);
    }

    // hidden
    bool comparator(int a, int b) { 
        return a < b;
    }

    // hidden
    int calc_length(int n) {
        return (2 * pow((int) ceil(log2(n)), 2)) - 1;
    }

    // hidden
    int construct(vector<int> &inp, int left, int right, vector<int> &vect, int index) {
        int ret;

        if(left == right) {
            vect[index] = inp[left];
            ret = vect[index];
        }
        else {
            int mid = (left + right) / 2, a, b;
            a = construct(inp, left, mid, vect, (2 * index) + 1);
            b = construct(inp, mid + 1, right, vect, (2 * index) + 2);
            if(comparator(a, b)) vect[index] = a;
            else vect[index] = b;
            ret = vect[index];
        }

        return ret;
    }

    // visible
    void create(vector<int> &inp) {
        if(inp.size() < 1) {
            cout << "EMPTY INPUT ERROR!";
            exit(0);
        }
        N = inp.size();
        vect.resize(calc_length(N));
        construct(inp, 0, N - 1, vect, 0);
    }

    // hidden
    int do_update(int i, int val, int left, int right, vector<int> &vect, int index) {
        int ret;

        if(left == right) {
            vect[index] = val;
            ret = vect[index];
        }
        else {
            int mid = (left + right) / 2, a;
            if(i <= mid) a = do_update(i, val, left, mid, vect, (2 * index) + 1);
            else a = do_update(i, val, mid + 1, right, vect, (2 * index) + 2);
            if(comparator(a, vect[index])) vect[index] = a;
            ret = vect[index];
        }

        return ret;
    }

    // visible
    void update(int i, int val) {
        if(i < 0 || i >= N) {
            cout << "OUT OF RANGE ERROR!";
            exit(0);
        }
        do_update(i, val, 0, N - 1, vect, 0);
    }

    // hidden
    int do_query(int q_left, int q_right, int left, int right, vector<int> &vect, int index) {
        int ret;

        if(q_left <= left && right <= q_right) ret = vect[index];
        else {
            int mid = (left + right) / 2, a, b;
            if(q_right <= mid) ret = do_query(q_left, q_right, left, mid, vect, (2 * index) + 1);
            else if(q_left > mid) ret = do_query(q_left, q_right, mid + 1, right, vect, (2 * index) + 2);
            else {
                a = do_query(q_left, q_right, left, mid, vect, (2 * index) + 1);
                b = do_query(q_left, q_right, mid + 1, right, vect, (2 * index) + 2);
                if(comparator(a, b)) ret = a;
                else ret = b;
            }
        }

        return ret;
    }

    // visible
    int query(int q_left, int q_right) {
        if(!(q_left <= q_right && 0 <= q_left && q_right < N - 1)) {
            cout << "OUT OF RANGE ERROR!";
            exit(0);
        }
        return do_query(q_left, q_right, 0, N - 1, vect, 0);
    }
    
    // visible
    void reset() {
        N = 0;
        vect.resize(0);
    }

    // visible
    void delete_all() {
        vect.clear();
        reset();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, ans;
    for(t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}