#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, ans, N, i, j;
    long long sum;
    double sq;
    vector<long long> vect, k, c;
    for(t = 1; t <= T; t++) {
        cin >> N;

        vect.resize(N + 1);
        for(i = 1; i <= N; i++) cin >> vect[i];

        vect[0] = 0;
        for(i = 1; i <= N; i++) vect[i] += vect[i - 1];

        k.resize(0);
        c.resize(0);
        k.emplace_back(0);
        c.emplace_back(1);
        for(i = 1; i <= N; i++) {
            if(k[k.size() - 1] == vect[i]) c[c.size() - 1]++;
            else {
                k.emplace_back(vect[i]);
                c.emplace_back(1);
            }
        }

        ans = 0;
        for(i = 1; i < k.size(); i++) {
            for(j = i; j < k.size(); j++) {
                sum = vect[j] - vect[i - 1];
                sq = sqrt(sum);
                if(sq - (long long)sq == 0.0) {
                    ans += c[j] * c[i - 1];
                }
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}