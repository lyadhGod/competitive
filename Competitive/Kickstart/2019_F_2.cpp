#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, N, S, i, c, j;
    long long ans;
    vector<unordered_set<int>> vect;
    for(t = 1; t <= T; t++) {
        cin >> N >> S;

        vect.resize(N);
        for(i = 0; i < N; i++) {
            vect[i].clear();

            cin >> c;
            while(c--) {
                cin >> j;
                vect[i].emplace(j);
            }
        }

        ans = 0LL;
        for(i = 0; i < N - 1; i++) {
            for(j = i + 1; j < N; j++) {
                for(int k : vect[i]) {
                    if(vect[j].find(k) == vect[j].end()) {
                        ans++;
                        break;
                    }
                }
                for(int k : vect[j]) {
                    if(vect[i].find(k) == vect[i].end()) {
                        ans++;
                        break;
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}