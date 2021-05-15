#include<bits/stdc++.h>
using namespace std;

bool check_dfs(unordered_map<char, unordered_set<char>> &supports, 
    char ch,     
    unordered_map<char, int> &check_backedge
    ) {
        bool ret = true;

        if(check_backedge[ch] == 0) {
            check_backedge[ch] = 1;

            unordered_set<char>::iterator i;
            for(i = supports[ch].begin(); i != supports[ch].end(); i++) {
                if(!check_dfs(supports, *i, check_backedge)) {
                    ret = false;
                    break;
                }
            }

            check_backedge[ch] = 2;
        }
        else if(check_backedge[ch] == 1) {
            ret = false;
        }
        else if(check_backedge[ch] == 2) {
            ret = true;
        }

        return ret;
    }

void calc_dfs(unordered_map<char, unordered_set<char>> &supports, 
    char ch,     
    unordered_map<char, int> &height,
    int count
    ) {
        if(height[ch] < count) {
            unordered_set<char>::iterator i;
            for(i = supports[ch].begin(); i != supports[ch].end(); i++) {
                calc_dfs(supports, *i, height, count + 1);
            }
        }
    }

void ans_dfs(unordered_map<char, unordered_set<char>> &supports, 
    char ch,     
    unordered_map<char, int> &height,
    int count,
    string &ans
    ) {
        if(height[ch] == (count + 1)) {
            ans += ch;
            unordered_set<char>::iterator i;
            for(i = supports[ch].begin(); i != supports[ch].end(); i++) {
                calc_dfs(supports, *i, height, count + 1);
            }
        }
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, R, C, i, j;
    string ans;
    vector<string> vect;
    unordered_map<char, unordered_set<char>> supports;
    unordered_map<char, unordered_set<char>>::iterator iter;
    unordered_map<char, int> check_backedge, height;
    for(t = 1; t <= T; t++) {
        cin >> R >> C;

        vect.resize(R);
        for(i = 0; i < R; i++) {
            cin >> vect[i];
        }

        supports.clear();
        for(j = 0; j < C; j++) {
            for(i = R - 2; i >= 0; i--) {
                supports[vect[i + 1][j]].emplace(vect[i][j]);
            }
        }
        for(iter = supports.begin(); iter != supports.end(); iter++) {
            if(iter->second.find(iter->first) != iter->second.end()) {
                iter->second.erase(iter->first);
            }
        }

        for(iter = supports.begin(); iter != supports.end(); iter++) {
            cout << iter->first;
        }
        
        ans = "";
        for(iter = supports.begin(); iter != supports.end(); iter++) {
            for(iter = supports.begin(); iter != supports.end(); iter++) {
                check_backedge[iter->first] = 0; cout << 'l';
            }
/**
            if(check_dfs(supports, iter->first, check_backedge)) {
                for(iter = supports.begin(); iter != supports.end(); iter++) {
                    height[iter->first] = 0;
                }
                calc_dfs(supports, iter->first, height, 1);
                ans_dfs(supports, iter->first, height, 0, ans);
                break;
            }
*/
        }
        if(ans.compare("") == 0) ans = "-1";
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}