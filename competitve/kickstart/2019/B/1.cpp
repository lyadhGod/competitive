#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

bool best(vector<vector<int>> &vect, int N, vector<vector<pair<int, int>>> &impact, vector<bool> &seen, int &m, int index, int time, int t, int level) {
    seen[index] = true;

    bool f = false, state = false;
    int ans, i;
    for(i = 0; i < N - 1; i++) {
        if(seen[impact[index][i].second] == false) {
            f = true;

            for(int k = 0; k < level; k++) cout << "\t";
            cout << index << "->" << impact[index][i].second << " [ " << t + max(0, vect[i][1] - time * vect[i][2]) << " ] " << "\n";
            if(best(vect, N, impact, seen, m, impact[index][i].second, time + vect[i][0], t + max(0, vect[i][1] - time * vect[i][2]), level + 1) == true) {
                state = true;
                break;
            }
        }
    }

    if(state == false && f == false) {
        if(t >= m) m = t;
        else state = true;
    }
   
    seen[index] = false;
    
    return state;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i;
    vector<vector<int>> vect(100 + 10);
    vector<vector<pair<int, int>>> impact(100 + 10);
    for(i = 0; i < vect.size(); i++) vect[i].resize(3), impact[i].resize(100 + 10);

    int T;
    cin >> T;

    int N, t, j, ans, m, index, p, k, q;
    vector<bool> seen(100 + 10);
    for(t = 1; t <= T; t++) {
        cin >> N;
        for(i = 0; i < N; i++) {
            cin >> vect[i][0] >> vect[i][1] >> vect[i][2];
            vect[i][3] = 0;
        }

        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if(i != j) impact[i][j] = pair<int, int>(vect[i][0] * vect[j][2], j);
                else impact[i][j] = pair<int, int>(INT_MIN, j);
            }
            sort(impact[i].begin(), impact[i].begin() + N, comp);

            for(j = 0; j < N - 1; j++) {
                cout << "[" << impact[i][j].first << ", " << impact[i][j].second << "]";
            }
            cout << "\n";
        }

        p = INT_MIN;
        for(i = 0; i < N; i++) {
            if(vect[i][2] > p) {
                p = vect[i][2];
                index = i;
            }
        }

        k = INT_MIN;
        for(i = 0; i < N; i++) {
            if(vect[i][2] == p && vect[i][0] > k) {
                p = vect[i][0];
                index = i;
            }
        }

        q = INT_MIN;
        for(i = 0; i < N; i++) {
            if(vect[i][0] == k && vect[i][2] == p && vect[i][1] > q) {
                q = vect[i][1];
                index = i;
            }
        }

        for(i = 0; i < N; i++) seen[i] = false;

        m = INT_MIN;
        best(vect, N, impact, seen, m, index, vect[index][0], vect[index][1], 0);

        cout << "Case #" << t << ": " << m << "\n";
    }

    return 0;
}