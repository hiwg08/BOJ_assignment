#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define MAX 1000000000

using namespace std;

ll T;

pll solve(ll a, ll b, ll s0, ll s1, ll t0, ll t1)
{
	if (b == 0)
		return { s0, t0 };

	ll quo = a / b, remain = a % b;

	return solve(b, remain, s1, s0 - (s1 * quo), t1, t0 - (t1 * quo));
}

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		ll K, C; cin >> K >> C;

		pll Ans = solve(K, C, 1, 0, 0, 1);

		if (gcd(K, C) != 1)
			cout << "IMPOSSIBLE" << '\n';

		else
		{
			while (true)
			{
				if (Ans.f < 0 && Ans.s > 0)
					break;
				Ans.f -= C, Ans.s += K;
			}

			Ans.s > MAX ? cout << "IMPOSSIBLE" << '\n' : cout << Ans.s << '\n';
		}
	}
}