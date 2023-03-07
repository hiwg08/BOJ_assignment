#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

vector<pll> V;

ll min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;

pll match(vector<ll>& T1, vector<ll> T2) // T1[0] = A, T1[1] = B, T1[2] = E
                                            // T2[0] = C, T2[1] = D, T2[2] = F
{
    ll A = T1[0], B = T1[1], E = T1[2], C = T2[0], D = T2[1], F = T2[2];
    
    double new_x = (double)(B * F - E * D) / (A * D - B * C);
    
    double new_y = (double)(E * C - A * F) / (A * D - B * C);
    
    if (A * D == B * C)
        return {LLONG_MIN, LLONG_MIN};
    if (((B * F - E * D) % (A * D - B * C) != 0) || ((E * C - A * F) % (A * D - B * C) != 0))
        return {LLONG_MIN, LLONG_MIN};
    
    return {(ll)new_x, (ll)new_y};
}

vector<vector<ll>> L;

vector<string> solution(vector<vector<int>> line) { // implementation
    vector<string> answer;
    
    L.resize((ll)line.size());
    
    for (ll i = 0; i < (ll)line.size(); i++)
    {
        for (ll j = 0; j < (ll)line[i].size(); j++)
            L[i].push_back((ll)line[i][j]);
    }
    
    for (ll i = 0; i < (ll)L.size(); i++)
    {
        for (ll j = i + 1; j < (ll)L.size(); j++)
        {
            vector<ll> A = L[i], B = L[j];
            
            pll chk = match(A, B);
            
            if (chk.x != LLONG_MIN)
                V.push_back({chk.x, chk.y});
        }
    }
    
    sort(V.begin(), V.end());
    
    V.erase(unique(V.begin(), V.end()), V.end());
    
    for (ll i = 0; i < (ll)V.size(); i++)
    {
        min_x = min(min_x, V[i].x), max_x = max(max_x, V[i].x);
        min_y = min(min_y, V[i].y), max_y = max(max_y, V[i].y);
    }
    
    for (ll i = max_y; i >= min_y; i--)
    {
        string tmp = "";
        for (ll j = min_x; j <= max_x; j++)
        {
            bool chk = false;
            for (auto e : V)
            {
                if (e.x == j && e.y == i)
                {
                    chk = true;
                    tmp += '*';
                    break;
                }
            }
            if (!chk)
                tmp += '.';
        }
        answer.push_back(tmp);
    }
    
    return answer;
}