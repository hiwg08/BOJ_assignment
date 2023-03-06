#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pob pop_back

using namespace std;

ll total = LLONG_MIN;

vector<ll> inte;

vector<char> oper;

vector<char> check, order; // order에는 연산자 순위가 담기는 배열

bool Vis[3]{ 0 };

ll calc()
{
    vector<ll> ans;

    vector<char> another_oper;

    vector<ll> cpy = inte;

    vector<char> cpy_oper = oper;

    for (int k = 0; k < (ll)order.size(); k++)
    {
        ans.pb(cpy[0]);

        for (ll i = 1; i < (ll)cpy.size(); i++) // cpy가 기준, ans가 정답.
        {
            if (cpy_oper[i - 1] == order[k])
            {
                if (cpy_oper[i - 1] == '+')
                    ans.back() += cpy[i];
                if (cpy_oper[i - 1] == '*')
                    ans.back() *= cpy[i];
                if (cpy_oper[i - 1] == '-')
                    ans.back() -= cpy[i];
            }
            else
            {
                another_oper.pb(cpy_oper[i - 1]);
                ans.pb(cpy[i]);
            }
        }
        cpy = ans;
        cpy_oper = another_oper;
        ans.clear();
        another_oper.clear();
    }

    return abs(cpy[0]);
}

void solve(int Idx)
{
    if (Idx >= (ll)check.size())
    {
        total = max(total, calc());
        return;
    }

    for (ll i = 0; i < (ll)check.size(); i++)
    {
        if (Vis[i])
            continue;
        
        Vis[i] = true;
        order.pb(check[i]);
        
        solve(Idx + 1);
        
        Vis[i] = false;
        order.pob();
    }
}

ll solution(string expression) { // bruteforcing(backtracking), data structure(stack), math
    ll answer = 0;

    string tmp = "";
    
    for (auto e : expression)
    {
        if (e >= '0' && e <= '9')
            tmp += e;
        else
        {
            inte.pb(stoll(tmp));
            oper.pb(e);
            check.pb(e);
            tmp = "";
        }
    }

    inte.pb(stoll(tmp));

    sort(check.begin(), check.end());

    check.erase(unique(check.begin(), check.end()), check.end());

    solve(0);

    return total;
}