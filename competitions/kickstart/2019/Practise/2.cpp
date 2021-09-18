#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N, i, K, sum, max, t;
    string s_num;
    vector<int> vect((int) 1e7);
    for(t = 1; t <= T; t++) {
        cin >> N;
        cin >> s_num;

        for(i = 0; i < N; i++) vect[i] = (int) s_num[i] - 48;

        K = (int) ceil((double) N / 2);
        
        sum = 0;
        for(i = 0; i < K; i++) sum += vect[i];

        max = sum;
        for(; i < N; i++) {
            sum += vect[i] - vect[i - K];
            if(sum > max) max = sum;
        }

        cout << "Case #" << t << ": "  << max << endl;
    }

    return 0;
}