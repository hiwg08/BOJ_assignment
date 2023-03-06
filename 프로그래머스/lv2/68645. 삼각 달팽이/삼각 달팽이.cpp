#include <bits/stdc++.h>

using namespace std;

int N, total, cnt;

int nx = -1, ny = 0;

int Map[1001][1001]{ 0 };

void first()
{   
    for (int i = 1; i <= total; i++)
        Map[++nx][ny] = ++cnt;
}
void second()
{
    for (int i = 1; i <= total; i++)
        Map[nx][++ny] = ++cnt;
}
void third()
{
     for (int i = 1; i <= total; i++)
        Map[--nx][--ny] = ++cnt;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    N = n, total = n;
    
    while(true)
    {
        first();
        if (--total == 0) break;
        
        second();
        if (--total == 0) break;
        
        third();
        if (--total == 0) break;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Map[i][j] == 0)
                break;
            answer.push_back(Map[i][j]);
        }
    }
   
    return answer;
}