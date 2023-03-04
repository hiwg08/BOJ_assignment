#include <bits/stdc++.h>

using namespace std;

int N;

int cnt = 0;

int dx[]{1, 1, 0, 1, 1};

long long DP[21]{ 0 };

int solve(long long Idx, long long remain)
{
    if (remain == 1)
        return dx[Idx];
    
    if (Idx / DP[remain - 1] == 2)
        return 0;
    
   return solve(Idx % DP[remain - 1], remain - 1); 
}

int solution(int n, long long l, long long r) { // divide conquer
    
    N = n;
    
    for (long long i = 1; i <= 20; i++)
        i == 1 ? DP[i] = 5 : DP[i] = DP[i - 1] * 5;
    
    for (long long i = l; i <= r; i++)
        cnt += solve(i - 1, N);
        
    return cnt;
}