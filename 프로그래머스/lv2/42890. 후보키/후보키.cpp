#include <bits/stdc++.h>

using namespace std;

int N, M;

string Map[21][21];

bool Vis[21]{ 0 };

bool minimal[21]{ 0 };

bool Vis_minimal[40001]{ 0 };

vector<int> V;

vector<string> ans;

void reconstruct(string params)
{
    set<string> chk; // 중복된 수 확인. 범위가 작아서 set 써도 될 듯 하다.
    
    for (int i = 0; i < N; i++) // 이게 기본 뼈대이다.
    {
        string tmp = "";
        for (auto e : V)
            tmp += Map[i][e];
        chk.insert(tmp);
    }
    
    if ((int)chk.size() == N)
        ans.push_back(params);
}

void solve(int Idx, int cnt, int select, string S)
{
    if (cnt == select)
    {
        reconstruct(S);
        return;
    }
    for (int i = Idx; i < M; i++)
    {
        if (Vis[i])
            continue;
        
        Vis[i] = true;
        V.push_back(i);
        solve(i + 1, cnt + 1, select, S + to_string(i));
        Vis[i] = false;
        V.pop_back();
    }
}

int solution(vector<vector<string>> relation) { // bruteforcing + implementation
    
    int total = 0;
    
    N = (int)relation.size(), M = (int)relation[0].size();
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            Map[i][j] = relation[i][j];
    }
    
    for (int i = 1; i <= M; i++)
    {
        solve(0, 0, i, "");
    }
    
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (Vis_minimal[i])
            continue;
        
        for (int j = i + 1; j < (int)ans.size(); j++)
        {
            if (Vis_minimal[j])
                continue;
            
            string tmp = "";
            
            for (int q = 0; q < (int)ans[i].size(); q++)
            {
                for (int w = 0; w < (int)ans[j].size(); w++)
                {
                    if (ans[i][q] == ans[j][w])
                    {
                        tmp += ans[i][q];
                        break;
                    }
                }
            }
            
            if (tmp == ans[i])
                Vis_minimal[j] = true;
        }
    } // 4중 for문?
    
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (!Vis_minimal[i])
            total++;
    }
    
    
    return total;
}