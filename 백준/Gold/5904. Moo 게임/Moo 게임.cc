#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

ll solve(ll T)
{
	if (T == 0)
		return 3;

	ll ret = solve(T - 1);

	return (2 * ret) + (T + 3);
}

void solve_2(ll Idx, ll K)
{
	if (Idx == 0)
	{
		K == 1 ? cout << 'm' : cout << 'o';
		cout << '\n';
		return;
	}

	ll T = solve(Idx - 1);

	if (K <= T)
		solve_2(Idx - 1, K);

	else if (K > T + Idx + 3)
		solve_2(Idx - 1, K - T - Idx - 3);

	else
	{
		K == T + 1 ? cout << 'm' : cout << 'o';
		cout << '\n';
	}
}

int main()
{
	cin >> N;

	ll Idx = 0;

	while (true)
	{
		if (solve(Idx) >= N)
			break;
		Idx++;
	}

	solve_2(Idx, N);
}