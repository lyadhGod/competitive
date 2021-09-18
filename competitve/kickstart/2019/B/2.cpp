#include<bits/stdc++.h>
using namespace std;

struct node {
    int S, E, L, E_L;
};

bool comp_E_greater(node prev, node next) {
    return prev.E > next.E;
}

bool comp_E_L_less(node prev, node next) {
    return prev.E_L < next.E_L;
}

bool comp_S_less(node prev, node next) {
    return prev.S < next.S;
}

int main() {
    int T;
    cin >> T;

    int N, zero, nonzero, i, S, E, L, ans, t, sec, residue;
    vector<node> vect_zero(110), vect_nonzero(110);
    for(t = 1; t <= T; t++) {
        cin >> N;

        for(zero = 0, nonzero = 0; N; N--) {
            cin >> S >> E >> L;

            if(L == 0) {
                vect_zero[zero].S = S;
                vect_zero[zero].E = E;
                vect_zero[zero].L = L;
                vect_zero[zero].E_L = INT_MAX;
                zero++;
            }
            else {
                vect_nonzero[nonzero].S = S;
                vect_nonzero[nonzero].E = E;
                vect_nonzero[nonzero].L = L;
                vect_nonzero[nonzero].E_L = (int) ceil((double) E / L);
                nonzero++;
            }
        }

        ans = 0;
        if(nonzero > 0) {
            stable_sort(vect_nonzero.begin(), vect_nonzero.begin() + nonzero, comp_E_greater);
            stable_sort(vect_nonzero.begin(), vect_nonzero.begin() + nonzero, comp_E_L_less);
            stable_sort(vect_nonzero.begin(), vect_nonzero.begin() + nonzero, comp_S_less);
        
            i = 0;
            ans = vect_nonzero[i].E;
            sec = vect_nonzero[i].S;
            for(i++; i < nonzero; i++) {
                if(vect_nonzero[i].E_L - sec > 0) {
                    ans += vect_nonzero[i].E - (sec * vect_nonzero[i].L);
                    sec += vect_nonzero[i].S;
                }
            }
        }
        for(i = 0; i < zero; i++) ans += vect_zero[i].E;

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}