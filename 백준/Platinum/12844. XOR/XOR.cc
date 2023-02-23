#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, M;

ll seg[500001 * 4]{ 0 }, lazy[500001 * 4]{ 0 }, Arr[500001]{ 0 };

ll init(ll node, ll start, ll end)
{
	if (start == end)
	{
		seg[node] = Arr[start];
		return seg[node];
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return seg[node] = init(L, start, mid) ^ init(R, mid + 1, end);
}

void propagate(ll node, ll start, ll end)
{
	if (lazy[node] != 0)
	{
		if (((end - start + 1) % 2) != 0)
			seg[node] ^= lazy[node];

		if (start != end)
		{
			lazy[2 * node] ^= lazy[node];
			lazy[2 * node + 1] ^= lazy[node];
		}

		lazy[node] = 0;
	}
}

ll update(ll node, ll start, ll end, ll cmd_a, ll cmd_b, ll params)
{
	propagate(node, start, end);

	if (cmd_a > end || cmd_b < start)
		return seg[node];

	if (cmd_a <= start && end <= cmd_b)
	{
		if (((end - start + 1) % 2) != 0)
			seg[node] ^= params;

		if (start != end)
		{
			lazy[2 * node] ^= params;
			lazy[2 * node + 1] ^= params;
		}

		return seg[node];
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return seg[node] = update(L, start, mid, cmd_a, cmd_b, params) ^ update(R, mid + 1, end, cmd_a, cmd_b, params);
}

ll solve(ll node, ll start, ll end, ll cmd_a, ll cmd_b)
{
	propagate(node, start, end);

	if (cmd_a > end || cmd_b < start)
		return 0;

	if (cmd_a <= start && end <= cmd_b)
		return seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return solve(L, start, mid, cmd_a, cmd_b) ^ solve(R, mid + 1, end, cmd_a, cmd_b);
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	init(1, 0, N - 1);

	cin >> M;

	for (ll i = 0, a, b, c, d; i < M; i++)
	{
		cin >> a >> b >> c;

		if (a == 2)
			cout << solve(1, 0, N - 1, b, c) << '\n';

		else
		{
			cin >> d;
			update(1, 0, N - 1, b, c, d);
		}
	}
}