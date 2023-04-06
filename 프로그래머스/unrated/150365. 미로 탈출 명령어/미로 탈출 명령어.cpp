#include <bits/stdc++.h>

using namespace std;

int DP[50][50][2501][4]{ 0 };

// d l r u

int dx[]{1, 0, 0, -1};
int dy[]{0, -1, 1, 0};

char q[]{'d', 'l', 'r', 'u'};

int N, M, X, Y, R, C, K;

char ans[2501];

void init()
{
    for (int i = 0; i <= 2500; i++)
        ans[i] = '.';
}

int solve(int nx, int ny, int move, int dir)
{
    if (move > K)
        return 0;
    
    if (nx == R && ny == C && move == K)
        return 1;
    
    int& ret = DP[nx][ny][move][dir];
    
    if (ret != -1)
        return ret;
    
    for (int i = 0; i < 4; i++)
    {
        int ni = nx + dx[i], nj = ny + dy[i];
        
        if (ni < 0 || nj < 0 || ni >= N || nj >= M)
            continue;
        
        if (solve(ni, nj, move + 1, i) == 1)
        {
            ans[move] = q[i];
            return ret = 1;
        }
    }
    
    return ret = 0;   
}



string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    init();
    
    N = n, M = m, X = x - 1, Y = y - 1, R = r - 1, C = c - 1, K = k;
    
    memset(DP, -1, sizeof(DP));
    
    if (solve(X, Y, 0, 0))
    {
        for (int i = 0; i <= 2500; i++)
        {
            if (ans[i] == '.')
                break;
            answer.push_back(ans[i]);
        }
    }
    else
        answer = "impossible";
    
    return answer;
}