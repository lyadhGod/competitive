#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    int i;
    vector<vector<int>> vect(250);
    for(i = 0; i < 250; i++) vect[i].resize(250);

    int t, R, C, j, z, temp_z, min_i, min_j, min;
    for(t = 1; t <= T; t++) {
        cin >> R >> C;

        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                cin >> vect[i][j];
            }
        }

        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                if(vect[i][j] == 1) {
                    if(i - 1 >= 0 && vect[i - 1][j] == 0) vect[i - 1][j] = 1;
                    if(i + 1 < R && vect[i + 1][j] == 0) vect[i + 1][j] = 1;
                    if(j - 1 >= 0 && vect[i][j - 1] == 0) vect[i][j - 1] = 1;
                    if(j + 1 < C && vect[i][j + 1] == 0) vect[i][j + 1] = 1;
                }
            }
        }

        z = 0;
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                if(vect[i][j] == 0)  z++;
            }
        }

        if(z == 0) cout << "Case #" << t << ": " << z << endl;
        else {
            min = INT_MAX;
            min_i = -1;
            min_j = -1;
            for(i = 0; i < R; i++) {
                for(j = 0; j < C; j++) {
                    if(vect[i][j] == 0) {
                        temp_z = 1;
                        if(i - 1 >= 0 && vect[i - 1][j] == 0) temp_z++;
                        if(i + 1 < R && vect[i + 1][j] == 0) temp_z++;
                        if(j - 1 >= 0 && vect[i][j - 1] == 0) temp_z++;
                        if(j + 1 < C && vect[i][j + 1] == 0) temp_z++;

                        if(z - temp_z < min) {
                            min = z - temp_z;
                            min_i = i; 
                            min_j = j;
                        }
                    }
                }
            }

            i = min_i;
            j = min_j;
            vect[i][j] = 1;
            if(i - 1 >= 0 && vect[i - 1][j] == 0) vect[i - 1][j] = 1;
            if(i + 1 < R && vect[i + 1][j] == 0) vect[i + 1][j] = 1;
            if(j - 1 >= 0 && vect[i][j - 1] == 0) vect[i][j - 1] = 1;
            if(j + 1 < C && vect[i][j + 1] == 0) vect[i][j + 1] = 1;

        }
    }

    return 0;
}