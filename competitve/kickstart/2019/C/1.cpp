#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int i, j;
    vector<vector<int>> vectR(5e1 + 5);
    vector<vector<int>> vectC(5e1 + 5);
    for(i = 0; i < vectR.size(); i++) {
        vectR[i].resize(5e1 + 5);
        vectC[i].resize(5e1 + 5);
    }

    int t, N, R, C, sR, sC, k, m;
    char direc;
    string instr;
    for(t = 1; t <= T; t++) {
        cin >> N >> R >> C >> sR >> sC;
        getline(cin, instr);
        getline(cin, instr);

        for(i = 1; i <= R; i++) {
            for(j = 1; j <= C; j++) {
                vectR[i][j] = -1;
                vectC[i][j] = -1;
            }
        }

        i = sR;
        j = sC;
        for(k = 0; k < instr.size(); k++) {
            direc = instr[k];
            do {
                if(direc == 'N') {
                    while(vectR[i][j] > 0) i = vectR[i][j];
                    
                    m = i - 1;
                    while(vectR[m][j] > 0) m = vectR[m][j];

                    vectR[m][j] += vectR[i][j];
                    vectR[i][j] = m;
                    
                    if(m == i - 1) i = m;
                    else i = m - 1;
                }
                else if(direc == 'S') {
                    while(vectR[i][j] > 0) i = vectR[i][j];
                    m = i - vectR[i][j];
                    
                    vectR[i][j] += vectR[m][j];
                    vectR[m][j] = i;
                    i = m;
                }
                else if(direc == 'W') {
                    while(vectC[i][j] > 0) j = vectC[i][j];
                    
                    m = j - 1;
                    while(vectC[i][m] > 0) m = vectC[i][m];

                    vectC[i][m] += vectC[i][j];
                    vectC[i][j] = m;
                    
                    if(m == j - 1) j = m;
                    else j = m - 1;
                }
                else {
                    while(vectC[i][j] > 0) j = vectC[i][j];
                    m = j - vectC[i][j];
                    
                    vectC[i][j] += vectC[i][m];
                    vectC[i][m] = j;
                    j = m;
                }
            } while(vectR[i][j] != -1 && vectC[i][j] != -1);

        }

        cout << "Case #" << t << ": " << i << " " << j << "\n";
    }

    return 0;
}