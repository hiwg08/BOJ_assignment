#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

vector<int> V;

vector<pii> Ans;

int K, cnt;

bool cmp(pii a, pii b)
{
    return a.x > b.x;
}

int solution(int k, vector<int> tangerine) { // 1. greedy + binary_search 2. tree_map
    
    V = tangerine;
    
    K = k;
    
    sort(V.begin(), V.end());
    
    for (int i = 0; i < (int)V.size(); i++)
    {
        int L_Idx = (int)(lower_bound(V.begin(), V.end(), V[i]) - V.begin());
        
        int R_Idx = (int)(lower_bound(V.begin(), V.end(), V[i] + 1) - V.begin());
        
        if (R_Idx - L_Idx != 0)
            Ans.push_back({R_Idx - L_Idx, V[i]});
        
        i = R_Idx - 1;
    }
    
    sort(Ans.begin(), Ans.end(), cmp);
    
    for (auto e : Ans) // K는 무조건 1개는 있으니까 예외 처리 없이 편하게 for문 돌리면 된다.
    {
        K -= e.x;
        cnt++;
        
        if (K <= 0)
            break;
    }
    
    return cnt;
}