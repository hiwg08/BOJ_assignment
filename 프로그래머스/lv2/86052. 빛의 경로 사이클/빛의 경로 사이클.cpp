#include <bits/stdc++.h>

using namespace std;

int N, M, cnt;

int Map[501][501]{ 0 };

bool Vis[501][501][4]{ 0 };

int dx[]{1, 0, -1, 0};
int dy[]{0, 1, 0, -1};

int conv_L[4]{0}, conv_R[4]{ 0 };

int conv[3][4]{ {0, 1, 2, 3}, {1, 2, 3, 0}, {3, 0, 1, 2} };

vector<int> ans;

void dfs(int x, int y, int dir)
{
    cnt++;
    
    Vis[x][y][dir] = true;
    
    int nx = x + dx[dir], ny = y + dy[dir];
    
    if (ny < 0) ny = M - 1;
    
    if (ny >= M) ny = 0;
    
    if (nx < 0) nx = N - 1;
    
    if (nx >= N) nx = 0;
    
    if (Vis[nx][ny][conv[Map[nx][ny]][dir]])
        return;
    
    dfs(nx, ny, conv[Map[nx][ny]][dir]);
}


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    N = (int)grid.size(), M = (int)grid[0].size();
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == 'S')
                Map[i][j] = 0;
            if (grid[i][j] == 'L')
                Map[i][j] = 1;
            if (grid[i][j] == 'R')
                Map[i][j] = 2;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                if (!Vis[i][j][dir])
                {
                    cnt = 0;
                    dfs(i, j, dir);
                    ans.push_back(cnt);
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}