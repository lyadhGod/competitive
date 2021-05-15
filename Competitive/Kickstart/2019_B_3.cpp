#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    int t, N, S, i, l, r, max, throw_count, throw_min;
    vector<int> vect((int) 1e5 + 10), assoc((int) 1e5 + 10);
    for(t = 1; t <= T; t++) {
        cin >> N >> S;
        for(i = 0; i < N; i++) cin >> vect[i], assoc[vect[i]] = 0;
        
        throw_count = 0;
        throw_min = 0;
        max = INT_MIN;
        for(l = 0, r = 0; r < N; r++) {
            assoc[vect[r]]++;
            if(assoc[vect[r]] == (S + 1)) throw_count += assoc[vect[r]];
            else if(assoc[vect[r]] > (S + 1)) throw_count++;

            while(throw_count > ((r - l + 1) - throw_count)) {
                if(assoc[vect[l]] == (S + 1)) throw_count -= assoc[vect[l]];
                else if(assoc[vect[l]] > (S + 1)) throw_count--;
                assoc[vect[l]]--;

                l++;
            }

            if(r - l + 1 > max) max = r - l + 1, throw_min = throw_count;
        }

        cout << "Case #" << t << ": " << max - throw_min << endl;
    }

    return 0;
}