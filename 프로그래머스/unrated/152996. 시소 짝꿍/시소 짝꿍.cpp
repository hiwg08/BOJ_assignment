#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int N;

long long solution(vector<int> weights) { // 이분 탐색
    long long answer = 0;
    
    V = weights;
    
    N = (int)V.size();
    
    sort(V.begin(), V.end());
    
    for (int i = 0; i < (int)V.size(); i++) // 2 3 4
    {
        int first_Idx = (int)(lower_bound(V.begin(), V.end(), V[i] + 1) - V.begin()) - 1;
        answer += first_Idx - i;
        
        if ((V[i] * 3) % 2 == 0)
        {
            int second_Idx = (int)(lower_bound(V.begin(), V.end(), (V[i] * 3) / 2) - V.begin());
            
            int third_Idx = (int)(lower_bound(V.begin(), V.end(), ((V[i] * 3) / 2) + 1) - V.begin());
            
            answer += third_Idx - second_Idx;
        }
        
        if ((V[i] * 4) % 3 == 0)
        {
            int second_Idx = (int)(lower_bound(V.begin(), V.end(), (V[i] * 4) / 3) - V.begin());
            
            int third_Idx = (int)(lower_bound(V.begin(), V.end(), ((V[i] * 4) / 3) + 1) - V.begin());
            
            answer += third_Idx - second_Idx;
        }
        
        int second_Idx = (int)(lower_bound(V.begin(), V.end(), (V[i] * 2)) - V.begin());
            
        int third_Idx = (int)(lower_bound(V.begin(), V.end(), (V[i] * 2) + 1) - V.begin());
        
            
        answer += third_Idx - second_Idx;
        
    }
    
    // 100 101 180 270 360
    
    return answer;
}