#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll s = 0, N, K;

vector<int> E;

bool check(ll Idx)
{
    ll T_K = K, SUM = 0;
    
    priority_queue<ll> PQ;
    
    for (ll i = 0; i <= Idx; i++)
    {
        PQ.push(E[i]);
        SUM += E[i];
    }
    
    while(!PQ.empty() && T_K > 0)
    {
        SUM -= PQ.top();
        PQ.pop();
        T_K--;
    }
    
    return N >= SUM;
}

ll solve()
{
    ll lo = 0, hi = s;

    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) >> 1;

        check(mid) ? lo = mid : hi = mid;
    }

    return lo;
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    N = n;
    
    K = k;
    
    s = (int)enemy.size();
    
    E = enemy;
    
    return solve() + 1;
}