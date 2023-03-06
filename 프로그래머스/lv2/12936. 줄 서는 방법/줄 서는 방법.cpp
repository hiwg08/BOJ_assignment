#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> V, ans;

int N;

void reconstruct(ll Idx, ll pows, ll select)
{
    if (pows == 1)
    {
        ans.push_back(V[0]);
        return;
    }

    ll quo = Idx / (pows / select), remain = Idx % (pows / select);

    ans.push_back(V[quo]);

    V.erase(V.begin() + quo);

    reconstruct(remain, pows / select, select - 1);
}

ll get_fact(ll params) // implementation (math + recursion)
{
    if (params == 1)
        return 1;
    return get_fact(params - 1) * params;
}

vector<int> solution(int n, ll k) { // bruteforcing

    N = n;

    for (int i = 1; i <= n; i++)
        V.push_back(i);
    
    ll U = get_fact(N);

    reconstruct(k - 1, U, N);

    return ans;
}