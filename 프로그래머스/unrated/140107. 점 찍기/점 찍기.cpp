#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll K, D;

ll cnt = 0;

ll solution(int k, int d) { // geometry
    
    K = (ll)k, D = (ll)d;
    
    for (ll x = D; x >= 0; x--) // x2 + y2 = d2
    {
        if (x % K != 0)
            continue;
        
        ll y = D * D - x * x;
        
        ll conv_y = (ll)sqrt(y);
        
        cnt += (1 + (conv_y / K)); // 왼쪽 1은 y 좌표 0 포함.
        
       // cout << y << '\n';
    }
    
    return cnt;
}