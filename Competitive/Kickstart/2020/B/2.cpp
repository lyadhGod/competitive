#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, i;
    long long ans, N, D;
    vector<long long> vect(1e3 + 10);
    for(t = 1; t <= T; t++) {
        cin >> N >> D;
        for(i = 0; i < N; i++) cin >> vect[i];

        for(i = N - 1; i >= 0; i--) {
            ans = vect[i] * (D / vect[i]);
            D = ans;
        }
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}