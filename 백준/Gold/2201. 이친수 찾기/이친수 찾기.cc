#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, DP[101]{ 0 }, Sum_DP[101]{ 0 };

void solve(ll carry, ll L, ll R)
{
	if (L <= 2)
	{
		if (L == 0) cout << "0";
		if (L == 1) cout << "1";
		if (L == 2) cout << "10";
		cout << '\n';
		exit(0);
	}

	ll nxt = L - R;

	for (ll i = 0; i <= 100; i++)
	{
		if (nxt <= Sum_DP[i])
		{
			cout << "10";

			ll T = i + 1;

			while (carry - (T++) > 2)
				cout << "0";

			if (i == 0) solve(i + 1, nxt, 1);
			else solve(i + 1, nxt, Sum_DP[i - 1] + 1);
		}
	}
}

int main()
{
	cin >> N;

	DP[0] = 1, DP[1] = 1;

	Sum_DP[0] = 1, Sum_DP[1] = 2;

	for (ll i = 2; i <= 100; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];

		Sum_DP[i] = Sum_DP[i - 1] + DP[i];

		if (Sum_DP[i] >= N)
			solve(i + 1, N, Sum_DP[i - 1] + 1);
	}
}