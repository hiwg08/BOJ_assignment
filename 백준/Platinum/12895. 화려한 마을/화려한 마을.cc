#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

char c;

ll N, T, Q;

ll seg[100001 * 4]{ 0 }, lazy[100001 * 4]{ 0 };

void lazy_init()
{
	for (ll i = 0; i <= 400003; i++)
		lazy[i] = -1;
}

ll Init(ll node, ll start, ll end)
{
	ll& ret = seg[node];

	if (start == end)
		return ret = o << 0;

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return ret = Init(L, start, mid) | Init(R, mid + 1, end);
}

void propagate(ll node, ll start, ll end)
{
	if (lazy[node] != -1)
	{
		seg[node] = o << lazy[node];

		if (start != end)
		{
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

ll update(ll node, ll start, ll end, ll cmd_a, ll cmd_b, ll params)
{
	propagate(node, start, end);

	ll& ret = seg[node];

	if (cmd_b < start || cmd_a > end)
		return ret;

	if (cmd_a <= start && end <= cmd_b)
	{
		ret = o << params;

		if (start != end)
		{
			lazy[2 * node] = params;
			lazy[2 * node + 1] = params;
		}

		return ret;
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return ret = update(L, start, mid, cmd_a, cmd_b, params) | update(R, mid + 1, end, cmd_a, cmd_b, params);
}

ll ans(ll node, ll start, ll end, ll cmd_a, ll cmd_b)
{
	propagate(node, start, end);

	if (cmd_b < start || cmd_a > end)
		return 0;

	if (cmd_a <= start && end <= cmd_b)
		return seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return ans(L, start, mid, cmd_a, cmd_b) | ans(R, mid + 1, end, cmd_a, cmd_b);
}

int main()
{
	fastio;

	cin >> N >> T >> Q;

	lazy_init();

	Init(1, 0, N - 1);

	for (ll i = 0, q, w, e; i < Q; i++)
	{
		cin >> c;

		if (c == 'C')
		{
			cin >> q >> w >> e;

			if (q > w) swap(q, w);
			
			update(1, 0, N - 1, q - 1, w - 1, e - 1);
		}
		else
		{
			cin >> q >> w;

			if (q > w) swap(q, w);

			cout << (int)__builtin_popcount((unsigned int)ans(1, 0, N - 1, q - 1, w - 1)) << '\n';
		}
	}
}