#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int T;
    cin >> T;

    int t, N, G, M, i, j, temp;
    vector<vector<int>> groupC, groupA, state;
    vector<int> vectG;
    vector<char> vectO;
    for(t = 1; t <= T; t++) {
        cin >> N >> G >> M;

        groupC.resize(N);
        groupA.resize(N);
        for(i = 1; i <= N; i++) {
            groupC[i].resize(0);
            groupA[i].resize(0);
        }

        vectG.resize(G + 1);
        vectO.resize(G + 1);
        for(i = 1; i <= G; i++) {
            cin >> vectG[i];
            cin >> vectO[i];
            if(vectO[i] == 'C') groupC[vectG[i]].emplace_back(i);
            else groupA[vectG[i]].emplace_back(i);
        }

        state.resize(N);
        for(i = 1; i <= N; i++) {
            state[i].resize(2);
            if(groupC[i].size() > 0) state[i][0] = i; else state[i][0] = -1;
            if(groupA[i].size() > 0) state[i][1] = i; else state[i][1] = -1;
        }

        if(M >= N) M = M % N + N; 
        while(M--) {
            i = N;
            temp = state[i][0];
            for(; i >= 2; i--) state[i][0] = state[i - 1][0];
            state[i][0] = temp;

            i = 1;
            temp = state[i][1];
            for(; i <= N - 1; i++) state[i][1] = state[i + 1][1];
            state[i][1] = temp;
        }

        for(i = 1; i <= G; i++) vectG[i] = 0;
        for(i = 1; i <= N; i++) {
            for(j = 0; j < vectN[i].size(); j++) vectG[vectN[i][j]]++;
        }

        cout << "Case #" << t << ": ";
        for(i = 1; i <= G; i++) cout << vectG[i] << " ";
        cout << "\n";
    }

    return 0;
}