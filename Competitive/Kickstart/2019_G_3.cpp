#include<bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    int t, N, i;
    
    vector<long long> A, B;
    for(t = 1; t <= T; t++) {
        cin >> N >> H;
        
        A.resize(N);
        for(i = 0; i < N; i++) cin >> A[i];

        B.resize(N);
        for(i = 0; i < N; i++) cin >> B[i];

        

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}