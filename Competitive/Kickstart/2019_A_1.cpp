#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    int N, P, i, j, temp;
    long long sum , a, min;
    vector<int> vect(100010);
    for(j = 1; j <= T; j++) {
        cin >> N >> P;
        for(i = 0; i < N; i++) cin >> vect[i];

        sort(vect.begin(), vect.begin() + N);

        a = 0;
        sum = 0;
        for(i = N - 2; i >= N - P; i--) {
            sum += (long long) vect[i + 1] - vect[i];
            a += (long long) sum;
        }

        temp = N - 1;
        min = a;
        for(; i >= 0; i--, temp--) {
            sum += (long long) (vect[i + 1] - vect[i]) 
                - (vect[temp] - vect[temp - 1]); 
            a += (long long) sum - ((vect[temp] - vect[temp - 1]) * (P - 1));
            
            if(a < min) min = a;
        }

        cout << "Case #" << j << ": " << min << endl;
    }

    return 0;
} 