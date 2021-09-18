#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, ans, N, a, b, c;
    for(t = 1; t <= T; t++) {
        cin >> N;

        N--;
        cin >> a;
        N--;
        cin >> b;

        ans = 0;
        while(N--) {
            cin >> c;

            if(b > a && b > c) ans++;

            a = b;
            b = c;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}