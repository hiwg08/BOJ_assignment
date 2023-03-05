#include <bits/stdc++.h>

using namespace std;

bool Vis[101]{ 0 };

vector<int> V, ans;

int cnt = 0;

void dfs(int Idx)
{
    Vis[Idx] = true;
    cnt++;
    
    if (Vis[V[Idx]])
        return;

    dfs(V[Idx]);
}

int solution(vector<int> cards) { // dfs(recursion) or bfs
    
    V.push_back(-1);
    
    for (int i = 0; i < cards.size(); i++)
        V.push_back(cards[i]);
    
    for (int i = 1; i < (int)V.size(); i++)
    {
        if (!Vis[i])
        {
            cnt = 0;
            dfs(i);
            ans.push_back(cnt);
        }
    }
    
    sort(ans.begin(), ans.end(), greater<int>());
    
    if ((int)ans.size() == 0 || (int)ans.size() == 1)
        return 0;
    
    return ans[0] * ans[1];
}