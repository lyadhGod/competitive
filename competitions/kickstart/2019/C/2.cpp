#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int i;
    vector<vector<int>> mat(300 + 5);
    for(i = 0; i < mat.size(); i++) mat[i].resize(300 + 5);

    int t, R, C, K, j, start, end;
    multiset<int> mSet;
    vector<int> startVect(300 + 5);
    vector<int> endVect(300 + 5);
    for(t = 1; t <= T; t++) {
        cin >> R >> C >> K;
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                cin >> mat[i][j];
            }
        }

        for(i = 0; i < R; i++) {
            startVect[i] = -1;
            endVect[i] = -1;
        }

        for(i = 0; i < R; i++) {
            mSet.clear();
            start = -1;
            end = -1;
            for(j = 0; j < C; j++) {
                mSet.emplace(mat[i][j]);
                if((*(mSet.end()--)) - (*mSet.begin()) <= K) {
                    end = j;
                }
            }
        }
    }

    return 0;
}