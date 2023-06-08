#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)

using namespace std;

ll T, A, B, total;

ll DP[50010]{ 0 };

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		total = 0;

		memset(DP, 0, sizeof(DP));

		DP[0] = 1;

		ll nu = 0;

		for (ll i = 1; i <= 500; i++)
		{
			nu += i;

			if (A + B < nu)
				break;

			for (ll j = A; j >= 0; j--) // 항상 최대치 (A가 곧 최대임)
			{
				if (j + i > 50000 || j + i > A)
					continue;

				add_mod(DP[j + i], DP[j]);

				if (DP[j + i])
				{
					ll ori = j + i, rev = nu - ori;

					if (ori <= A && (rev <= B && rev >= 0))
						add_mod(total, DP[j + i]);
				}
			}

			for (ll j = i - 1; j >= 0; j--)
			{
				if (j > A)
					continue;

				if (DP[j])
				{
					ll ori = j, rev = nu - ori;

					if (ori <= A && (rev <= B && rev >= 0))
						add_mod(total, DP[j]);
				}
			}
		}

		cout << total << '\n';
	}
}