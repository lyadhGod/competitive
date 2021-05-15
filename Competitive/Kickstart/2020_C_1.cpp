#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, ans, N, K, i, prev, inp, count;
    for(t = 1; t <= T; t++) {
        cin >> N >> K;

        ans = 0;

        cin >> inp;
        prev = inp;
        count = 1;
        for(i = 1; i < N; i++) {
            cin >> inp;

            if(inp == (prev - 1)) count++;
            else {
                if(prev == 1 && count >= K) ans++;
                count = 1;
            }

            prev = inp;
        }
        if(prev == 1 && count >= K) ans++;

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}