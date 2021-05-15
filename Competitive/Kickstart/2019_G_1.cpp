#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, N, M, Q, i, a;
    long long ans;
    vector<bool> pages(1e5 + 10);
    vector<int> count(1e5 + 10);
    for(t = 1; t <= T; t++) {
        cin >> N >> M >> Q;

        for(i = 1; i <= N; i++) pages[i] = true;
        while(M--) {
            cin >> a;
            pages[a] = false;
        }

        for(i = 1; i <= N; i++) {
            count[i] = 0;
            for(a = i; a <= N; a += i) {
                if(pages[a]) count[i]++;
            }
        }

        ans = 0;
        while(Q--) {
            cin >> a;
            ans += count[a];
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}