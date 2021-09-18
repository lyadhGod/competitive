#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int T;
    cin >> T;

    unsigned int t, N, Q, ans, i, count, val;
    vector<unsigned int> vect(1e5 + 10);
    set<unsigned int> index;
    for(t = 1; t <= T; t++) {
        cin >> N >> Q;
        for(i = 0; i < N; i++) cin >> vect[i];

        index.clear();
        for(i = 0; i < N; i++) {
            val = vect[i];

            count = 0;
            while(val > 0) count++, val &= val - 1;
            if(count % 2 == 1) index.emplace(i);
        }

        cout << "Case #" << t << ": ";
        while(Q--) {
            cin >> i >> val;
            
            if(index.find(i) != index.end()) index.erase(i);

            vect[i] = val;

            count = 0;
            while(val > 0) count++, val &= val - 1;
            if(count % 2 == 1) index.emplace(i);

            ans = 0;
            if(index.size() % 2 == 0) ans = N;
            else {
                ans = 
                max(
                    max((*index.begin() - 1) - (0) + 1, (N - 1) - (*index.begin() + 1) + 1),
                    max((*--index.end() - 1) - (0) + 1, (N - 1) - (*--index.end() + 1) + 1)
                );
            }
            cout << ans << " ";
        }
        cout << "\n";

    }

    return 0;
}