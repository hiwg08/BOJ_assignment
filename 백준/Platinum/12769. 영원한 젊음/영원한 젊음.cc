// refered by https://kimoyami.github.io/2019/04/05/2016-ACM-ICPC-World-Finals-E-Forever-Young/
// sol : parametric_search
// core idea : to catch that the base b is at most 1,000,000!! / other, to narrow the huge range of base b using binary search. 

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

ll n, m;

ll solve1() 
{
    ll tmp;

    for (ll i = 1000000; i >= 10; i--) 
    {
        tmp = n;

        ll res = 0, base = 1;

        bool flag = false;
        
        while (tmp) 
        {
            if (tmp % i >= 10) 
            {
                flag = true;
                break;
            }

            res += base * (tmp % i);
            base *= 10;
            tmp /= i;
        }

        if (flag)
            continue;

        if (res >= m)
            return i;
    }

    return 0;
}


ll x0, x1, x2;

ll solve2()
{
    ll res = 0;

    for (ll i = m; i < 1000; i++) 
    {
        x0 = i % 10, x1 = i / 10 % 10, x2 = i / 100;

        ll lo = 0, hi = (ll)1e18;

        if (x2 != 0)
            hi = (ll)1e9;

        while (lo <= hi) 
        {
            ll mid = (lo + hi) >> 1;

            ull tmp = x2 * mid * mid + x1 * mid + x0;

            if (tmp == n) 
            {
                res = max(res, mid);
                break;
            }

            else if (tmp > (ull)n)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    return res;
}


int main()
{
    cin >> n >> m;

    cout << max(solve1(), solve2()) << '\n';
}