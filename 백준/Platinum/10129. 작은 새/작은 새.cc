#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, T, K;

ll Arr[1000001]{ 0 };

pll mon[1000001];

pll seg[4 * 1000001];

pll init(ll node, ll start, ll end)
{
	if (start == end)
		return seg[node] = mon[start];

	pll& ret = seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	pll T1 = init(L, start, mid), T2 = init(R, mid + 1, end);

	if (T1.y == T2.y)
	{
		if (T1.x > T2.x)
			return ret = T1;
		return ret = T2;
	}

	if (T1.y < T2.y)
		return ret = T1;
	return ret = T2;
}

pll update(ll node, ll start, ll end, ll params)
{
	if (start == end)
		return seg[node] = mon[params];

	pll& ret = seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	if (params <= mid)
	{
		pll T1 = update(L, start, mid, params);

		if (T1.y == seg[R].y)
		{
			if (T1.x > seg[R].x)
				return ret = T1;
			return ret = seg[R];
		}

		if (T1.y < seg[R].y)
			return ret = T1;
		return ret = seg[R];
	}

	pll T1 = update(R, mid + 1, end, params);

	if (T1.y == seg[L].y)
	{
		if (T1.x > seg[L].x)
			return ret = T1;
		return ret = seg[L];
	}

	if (T1.y < seg[L].y)
		return ret = T1;
	return ret = seg[L];

}

void solve()
{
	ll ans = 0;

	mon[0] = { Arr[0], 0 };

	for (ll i = 1; i < K; i++)
		mon[i] = { Arr[i], Arr[0] <= Arr[i] };

	init(1, 0, K - 1);

	for (ll i = K, Idx = 0; i < N; i++, Idx++)
	{
		ll new_idx = Idx % K;

		if (seg[1].x > Arr[i])
			mon[new_idx].y = seg[1].y;
		else
			mon[new_idx].y = seg[1].y + 1;
		
		mon[new_idx].x = Arr[i];

		if (i == N - 1)
			ans = mon[new_idx].y;

		update(1, 0, K - 1, new_idx);
	}

	cout << ans << '\n';
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	cin >> T;

	while (T--)
	{
		cin >> K;

		solve();
	}
}