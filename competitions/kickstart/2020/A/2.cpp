#include<bits/stdc++.h>
using namespace std;

struct item {
    int weight, profit, stack;
};

int knapsack(vector<item> &inp, int total) {
    int i;
    vector<vector<int>> mat(inp.size());
    for(i = 0; i < inp.size(); i++) {
        mat[i].resize(total + 1);
        mat[i][0] = 0;
    }
    for(i = 1; i < mat[0].size(); i++) {
        mat[0][i] = 0;
    }

    int j, m, k;
    unordered_set<int> u_set;
    for(i = 1; i < mat.size(); i++) {
        for(j = 1; j < mat[i].size(); j++) {
            mat[i][j] = 0;

            if(j < inp[i].weight) {
                mat[i][j] = mat[i - 1][j];
            }
            else {
                if((mat[i - 1][j - inp[i].weight] + inp[i].profit) > mat[i - 1][j]) {
                    mat[i][j] = mat[i - 1][j - inp[i].weight] + inp[i].profit; 
                }
                else mat[i][j] = mat[i - 1][j];
            }
        }
    }

    i = mat.size() - 1;
    j = mat[i].size() - 1;
    return mat[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int i;
    vector<vector<int>> inp(50 + 10);
    for(i = 0; i < inp.size(); i++) inp[i].resize(30 + 10);

    int t, N, K, P, j, sum, a, ans;
    vector<item> vect((50 + 10) * (30 + 10));
    for(t = 1; t <= T; t++) {
        cin >> N >> K >> P;

        a = 0;
        for(i = 0; i < N; i++) {
            sum = 0;
            for(j = 0; j < K; j++) {
                cin >> inp[i][j];
                
                sum += inp[i][j];
                vect[a].profit = sum;
                vect[a].weight = j + 1;
                vect[a].stack = i;
                a++;
            }
        }

        ans = knapsack(vect, P);

        cout << "Case #" << t << ": " << ans << "\n"; 
    }

    return 0;
}

