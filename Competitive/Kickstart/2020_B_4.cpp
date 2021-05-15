#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;

    int t, W, H, L, U, R, D, req_area, hole_area, w_area, h_area, req_w_area, req_h_area;
    double ans;
    for(t = 1; t <= T; t++) {
        cin >> W >> H >> L >> U >> R >> D;

        req_area = (W - 1) * (H - 1);

        if(R == W && D == H) hole_area = (R - 1) * (D - 1);
        else if(R == W) hole_area = (R - 1) * D;
        else if(D == H) hole_area = R * (D - 1);
        else hole_area = R * D;

        w_area = W;
        h_area = H;

        if(R == W && D == H) {
            req_h_area = 0; 
            req_w_area = 0; 
        }
        else if(R == W && D != H) {
            req_h_area = H - D; 
            req_w_area = 0; 
        }
        else if(R != W && D == H) {
            req_h_area = 0; 
            req_w_area = W - R; 
        }
        else if(R != W && D != H) {
            req_h_area = H; 
            req_w_area = W; 
        }

        ans = (double) (req_area - hole_area + req_h_area + req_w_area) / (W * H);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}