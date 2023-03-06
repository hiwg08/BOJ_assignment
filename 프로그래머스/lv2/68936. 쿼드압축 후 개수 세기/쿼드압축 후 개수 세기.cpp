#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N;

int Map[1025][1025]{ 0 };

pii solve(int nx, int ny, int pows)
{
    bool z_cnt = 0, o_cnt = 0;
    
    for (int i = nx; i < nx + pows; i++)
    {
        for (int j = ny; j < ny + pows; j++)
            Map[i][j] == 0 ? z_cnt = true : o_cnt = true;
    }
    
    if (z_cnt && o_cnt)
    {
        pii T1 = solve(nx, ny, pows / 2);
        pii T2 = solve(nx, ny + (pows / 2), pows / 2);
        pii T3 = solve(nx + (pows / 2), ny, pows / 2);
        pii T4 = solve(nx + (pows / 2), ny + (pows / 2), pows / 2);
        
        return {T1.x + T2.x + T3.x + T4.x, T1.y + T2.y + T3.y + T4.y};
    }
    
    return {z_cnt, o_cnt};
}

vector<int> solution(vector<vector<int>> arr) {
    
    N = (int)arr.size();
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            Map[i][j] = arr[i][j];
    }
    
    pii ans = solve(0, 0, N);
    
    return {ans.first, ans.second};
}