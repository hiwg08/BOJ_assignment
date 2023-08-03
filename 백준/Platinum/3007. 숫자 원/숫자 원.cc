#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

ll A[10001]{ 0 }, B[10001]{ 0 };

void add_mod(ll& ret, ll params)
{
    ret += params;
    ret %= N;
}

void add(ll params, ll val) 
{
    ll ret = params;
    
    do 
    {
        A[ret] += val;
        add_mod(ret, 3);
    } while (ret != params);
}

ll init(ll params) 
{
    ll res = 0, mini = 0, tmp = params;

    do 
    {
        A[tmp] = res;
        mini = min(mini, A[tmp]);
        add_mod(tmp, 1);

        res -= B[tmp];
        add_mod(tmp, 1);

        res += B[tmp];
        add_mod(tmp, 1);

    } while (tmp != params);

    return mini;
}

int main() 
{
    cin >> N;

    for (int i = 0; i < N; i++) 
        cin >> B[i];

    if (N % 3 != 0) 
    {
        init(0);
        add(0, (B[1] - (A[0] + A[1] + A[2])) / 3);
    }
    else 
    {
        add(0, 1 - init(0));
        add(1, 1 - init(1));
        init(2);
        add(2, B[1] - (A[0] + A[1]));
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << '\n';
}