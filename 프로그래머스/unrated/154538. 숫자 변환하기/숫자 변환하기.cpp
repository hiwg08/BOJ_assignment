#include <bits/stdc++.h>

using namespace std;

int DP[1000001]{ 0 };

int solution(int x, int y, int n) { // dp 혹은 bfs
    
    memset(DP, 0x7f, sizeof(DP));
    
    DP[x] = 0;
    
    for (int i = x; i <= y; i++)
    {
        if (i - n >= 0 && DP[i - n] != 0x7f7f7f7f)
            DP[i] = min(DP[i], DP[i - n] + 1);  
        
        if (i % 2 == 0 && DP[i / 2] != 0x7f7f7f7f)
            DP[i] = min(DP[i], DP[i / 2] + 1);
        
        if (i % 3 == 0 && DP[i / 3] != 0x7f7f7f7f)
            DP[i] = min(DP[i], DP[i / 3] + 1);
    }
    
    if (DP[y] == 0x7f7f7f7f)
        return -1;
    
    return DP[y];
}