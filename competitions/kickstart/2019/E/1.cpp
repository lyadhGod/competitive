#include<bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> vect;

    DisjointSet() {
        vect.resize(0);
    }

    // visible
    void  initialize(int N) {
        if(N < 0) {
            cout << "INVALID INPUT ERROR!";
            exit(0);
        }
        vect.resize(N);
        for(int i = 0; i < vect.size(); i++) vect[i] = -1;
    }

    // hidden
    int get_index(int child) { 
        return child;
    }

    // visible
    int get_parent(int child) {
        child = get_index(child);
        if(child < 0 || child >= vect.size()) {
            cout << "OUT OF RANGE ERROR!";
            exit(0);
        }
        int parent = child; 
        while(vect[parent] >= 0) parent = vect[parent];
        if(child != parent) vect[child] = parent;
        return parent;
    }

    // visible
    bool unioning(int child_1, int child_2) {
        child_1 = get_index(child_1);
        child_2 = get_index(child_2);
        if(child_1 < 0 || child_1 >= vect.size() || child_2 < 0 || child_2 >= vect.size()) {
            cout << "OUT OF RANGE ERROR!";
            exit(0);
        }
        bool ret;

        int parent_1, parent_2; 
        parent_1 = get_parent(child_1); 
        parent_2 = get_parent(child_2);

        if(parent_1 == parent_2) ret = false;
        else {
            if(vect[parent_1] < vect[parent_2]) {
                vect[parent_1] += vect[parent_2];
                vect[parent_2] = parent_1;
            }
            else {
                vect[parent_2] += vect[parent_1];
                vect[parent_1] = parent_2;
            }
            ret = true;
        }

        return true;
    }

    // visible
    void reset() {
        initialize(vect.size());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    bool f;
    int t, ans, N, M, i, ans, parent_count, u, v;
    DisjointSet disjoint;
    for(t = 1; t <= T; t++) {
        cin >> N >> M;

        
        parent_count = N;

        f = true;
        ans = 0;
        for(i = 0; i < M && f == false; i++) {
            cin >> u;
            cin >> v;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}