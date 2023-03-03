#include <bits/stdc++.h>

using namespace std;

vector<int> lion, apache, ans;

int total = INT_MIN;

bool isBetter() 
{
    for (int i = 10; i >= 0; i--) {
        if (lion[i] > ans[i]) return true;
        else if (lion[i] < ans[i]) return false;
    }
}

void check()
{
    int l_s = 0, a_s = 0;

    for (int i = 0; i <= 10; i++)
    {
        if (lion[i] > apache[i])
            l_s += (10 - i);
        else if (apache[i] > 0)
            a_s += (10 - i);
    }

    if (l_s > a_s)
    {
        if (total <= l_s - a_s)
        {
            if (total == l_s - a_s && !isBetter())
                return;

            total = l_s - a_s;
            ans = lion;
        }
    }
}

void solve(int Sum, int Idx)
{
    if (Sum == 0)
    {
        check();
        return;
    }

    if (Idx >= 11)
    {
        lion[Idx - 1] += Sum;
        check();
        lion[Idx - 1] -= Sum;

        return;
    }
        

    if (Sum >= (apache[Idx] + 1))
    {
        lion[Idx] += (apache[Idx] + 1);
        solve(Sum - (apache[Idx] + 1), Idx + 1);
        lion[Idx] -= (apache[Idx] + 1);
    }

    solve(Sum, Idx + 1);
}

vector<int> solution(int n, vector<int> info) {
    apache = info;

    lion.resize(11, 0);

    ans.resize(11, -1);

    solve(n, 0);

    if (ans[0] == -1)
        return { -1 };

    return ans;
}