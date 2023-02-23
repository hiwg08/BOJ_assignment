#include <bits/stdc++.h>
#define ll long long
#define MAX (ll)2000000000 * (ll)30
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

ll N, M, Ans, Arr[10001]{ 0 };

pll able_play(ll standard)
{
	ll Cnt = 0;

	for (ll i = 0; i < M; i++)
		Cnt += standard / Arr[i];

	if (Cnt >= N - M) return { 1, Cnt };
	else return { 0, Cnt };
}

void solve()
{
	ll lo = -1, hi = MAX;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		pll T = able_play(mid);

		T.f ? hi = mid : lo = mid;
	}

	ll Interval = N - M - able_play(hi - 1).s;

	for (ll i = 0; i < M; i++)
	{
		if (hi % Arr[i] == 0)
		{
			if (--Interval == 0)
			{
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (ll i = 0; i < M; i++)
		cin >> Arr[i];

	if (N <= M)
	{
		cout << N << '\n';
		exit(0);
	}

	solve();
}