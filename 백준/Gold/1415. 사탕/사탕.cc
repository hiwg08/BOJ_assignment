#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, total;

deque<ll> V;

ll DP[500001]{ 0 };

bool Vis[500001]{ 0 };

void eratos()
{
	for (ll i = 2; i <= (ll)sqrt(500000); i++)
	{
		if (Vis[i])
			continue;
		for (ll j = i; j <= 500000; j += i)
		{
			if (j == i)
				continue;
			Vis[j] = true;
		}
	}
}

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
		cin >> iv;

	eratos();

	sort(V.begin(), V.end());

	ll Idx = 0;

	ll zero_cnt = (ll)(lower_bound(V.begin(), V.end(), 1) - V.begin()) - (ll)(lower_bound(V.begin(), V.end(), 0) - V.begin());

	DP[0] = zero_cnt + 1;

	while (zero_cnt--)
	{
		V.pop_front();
		N--;
	}

	while (Idx < N)
	{
		ll nxt = (ll)(lower_bound(V.begin(), V.end(), V[Idx] + 1) - V.begin());

		ll cnt = nxt - Idx;

		for (ll j = 500000; j >= 0; j--)
		{
			for (ll k = cnt; k >= 1; k--)
			{
				if (j + V[Idx] * k > 500000)
					continue;
				DP[j + V[Idx] * k] += DP[j];
			}
		}

		Idx = nxt;
	}

	for (ll i = 2; i <= 500000; i++)
	{
		if (!Vis[i])
			total += DP[i];
	}

	cout << total;
}