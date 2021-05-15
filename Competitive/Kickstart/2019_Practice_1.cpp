#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    int A, B, N, left, right, mid, temp_n;
    string ans;
    while(T--) {
        cin >> A >> B;
        cin >> N;
        
        left = A + 1;
        right = B;
        mid = (left + right) / 2;
        
        temp_n = N;
        while(temp_n--) {
            cout << mid << endl;
            cin >> ans;
            
            if(ans.compare("CORRECT") == 0) break;
            else if(ans.compare("TOO_SMALL") == 0) left = mid + 1;
            else if(ans.compare("TOO_BIG") == 0) right = mid - 1;
            else return 0;
            
            mid = (left + right) / 2;
        }
    }
        
    return 0;
}