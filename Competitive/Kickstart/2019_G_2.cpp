#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    int t, N, i, length = sizeof(unsigned long long) * 8 - 10, j;
    unsigned long long ans, M, max, mask, k;
    vector<unsigned long long> num(1e3 + 10), mini(length);
    vector<int> zero(length), one(length);
    for(t = 1; t <= T; t++) {
        cin >> N >> M;
        
        for(i = 0; i < N; i++) cin >> num[i];

        for(i = 0, mask = 1; i < length; i++, mask <<= 1) {
            one[i] = zero[i] = 0;
            for(j = 0; j < N; j++) {
                if(num[j] & mask) one[i]++;
                else zero[i]++;
            }
            if(one[i] <= zero[i]) mini[i] = mask * one[i];
            else mini[i] = mask * zero[i];
        }
        for(i = 1; i < length; i++) mini[i] += mini[i - 1];
        
        if(mini[length - 1] > M) cout << "Case #" << t << ": -1\n";
        else {            
            for(i = 0, mask = 1; i < length - 1; i++, mask <<= 1);

            ans = 0;
            for(i = length - 1; i > 0; i--, mask >>= 1) {
                k = zero[i] * mask + mini[i - 1];
                if(k > M) M -= mask * one[i];
                else {
                    ans += mask;
                    M -= mask * zero[i];
                }
            }
            if(zero[i] <= M) ans += mask;

            cout << "Case #" << t << ": " << ans << "\n";
        }
    }

    return 0;
}