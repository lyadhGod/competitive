#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int t;
    long long inp, base, last, k, count, up, down;
    bool p;
    for(t = 1; t <= T; t++) {
        cin >> inp;

        last = 0;
        k = inp;
        while(k > 0) {
            base *= 10;
            if((k % 10) % 2) last = base;
            k /= 10;
        }

        if(last == 0) count = 0;
        else {
            down = (inp * last * last / base)  
        }
        
        cout << "Case #" << t << ": " << count << endl;

    }

    return 0;
}