#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, M, Sum, MAX = INT_MIN, Arr[100001]{ 0 };

bool check(ll standard)
{
	ll Sum = 0, Cnt = 0;

	for (ll i = 0; i < N; i++)
	{
		Sum += Arr[i];

		if (Sum > standard)
		{
			Sum = Arr[i];
			Cnt++;
		}
	}

	if (Sum > 0)
		Cnt++;

	return Cnt <= M;
}

ll solve()
{
	ll lo = MAX - 1, hi = Sum;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) >> 1;

		check(mid) ? hi = mid : lo = mid;
	}

	return hi;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (ll i = 0; i < N; i++)
	{
		cin >> Arr[i];
		Sum += Arr[i];
		MAX = max(MAX, Arr[i]);
	}

	cout << solve() << '\n';
}