#include<bits/stdc++.h>
using namespace std;

void part(string &s, int &index, long long &row, long long &column) {    
    while(index < s.size() && 'A' <= s[index] && s[index] <= 'Z') {
        switch(s[index]) {
            case 'N': row--; break;
            case 'S': row++; break;
            case 'W': column--; break;
            case 'E': column++; break;
        }
        index++;
    }

    if(index < s.size() && '2' <= s[index] && s[index] <= '9') {
        long long r = 0LL, c = 0LL;
        int k = s[index] - '0';

        index++;        
        index++;        
        part(s, index, r, c);

        row += k * r;
        column += k * c;
    }
    else if(index < s.size() && s[index] == ')') {
        index++; 
        return;        
    }
    
    if(index < s.size()) part(s, index, row, column);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, index;
    long long row, column;
    string s;
    for(t = 1; t <= T; t++) {
        cin >> s;

        index = 0;
        row = column = 0;
        part(s, index, row, column);

        if(row >= 0) row = (row % (int) 1e9) + 1;
        else {
            int r = abs(row);
            r--;
            r %= (int) 1e9;

            row = (int) 1e9 - r;
        }

        if(column >= 0) column = (column % (int) 1e9) + 1;
        else {
            int c = abs(column);
            c--;
            c %= (int) 1e9;

            column = (int) 1e9 - c;
        }

        cout << "Case #" << t << ": " << column  << " " << row  << "\n";
    }

    return 0;
}