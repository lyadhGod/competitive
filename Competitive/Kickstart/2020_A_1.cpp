#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int t, N, B, i, l, r;
    long long sum, ans;
    vector<int> vect(1e5 + 10);
    for(t = 1; t <= T; t++) {
        cin >> N >> B;
        for(i = 0; i < N; i++) cin >> vect[i];

        sort(vect.begin(), vect.begin() + N);

        l = 0;
        r = 0;  
        sum = 0;
        ans = INT_MIN;
        for(i = 0; i < N; i++) {
            sum += vect[i];
            r++;
            while(l < r && sum > B) sum -= vect[l++];
            if(r - l > ans) ans = r - l;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}