#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, M, K, Arr[51]{ 0 }, cou;

string total = "";

bool check(ll standard)
{
	ll start = Arr[0], cnt = 1;

	for (ll i = 1; i < K; i++)
	{
		if (Arr[i] - start >= standard)
		{
			start = Arr[i];
			cnt++;
		}
	}

	return cnt >= M;
}

ll solve()
{
	ll lo = 1, hi = Arr[K - 1] - Arr[0] + 1;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		check(mid) ? lo = mid : hi = mid;
	}

	return lo;
}

int main()
{
	fastio;

	cin >> N >> M >> K;

	for (ll i = 0; i < K; i++)
		cin >> Arr[i];

	ll Ans = solve();

	cou = 1;

	ll start = INT_MIN;

	for (ll i = 0; i < K; i++)
	{
		if (Arr[i] - start >= Ans)
		{
			start = Arr[i];
			cou++ <= M ? total += '1' : total += '0';
		}
		else
			total += '0';
	}

	cout << total << '\n';
}