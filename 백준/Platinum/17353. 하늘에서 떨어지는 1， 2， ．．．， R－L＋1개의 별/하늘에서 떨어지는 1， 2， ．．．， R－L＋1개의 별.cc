#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M;

ll seg[100001 * 4]{ 0 }, Arr[100001]{ 0 };

pll lazy[100001 * 4];

void lazy_init()
{
	for (ll i = 0; i <= 400003; i++)
		lazy[i] = { 0, 0 };
}

void propagate(ll node, ll start, ll end)
{
	if (lazy[node].x != 0)
	{
		ll s = (end - start + 1), ori = (s * (s + 1)) >> 1;

		seg[node] += (ori * lazy[node].x) + (lazy[node].y * ((s + 1) >> 1));

		if (start != end)
		{
			lazy[2 * node].x += lazy[node].x;
			lazy[2 * node].y += lazy[node].y;

			lazy[2 * node + 1].x += lazy[node].x;
			lazy[2 * node + 1].y += lazy[node].y + lazy[node].x * ((s + 1) >> 1);
		}

		lazy[node] = { 0, 0 };
	}
}

ll Init(ll node, ll start, ll end)
{
	ll& ret = seg[node];

	if (start == end)
	{
		ret = Arr[start];
		return ret;
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return ret = Init(L, start, mid) + Init(R, mid + 1, end);
}

ll update(ll node, ll start, ll end, ll cmd_a, ll cmd_b)
{
	propagate(node, start, end);

	ll& ret = seg[node];

	if (cmd_a > end || cmd_b < start)
		return ret;

	if (cmd_a <= start && end <= cmd_b)
	{
		ll L_I = start - cmd_a, s = (end - start + 1), ori = (s * (s + 1)) >> 1;

		ret += ori + s * L_I;

		if (start != end)
		{
			lazy[2 * node].x += 1;
			lazy[2 * node].y += L_I;

			lazy[2 * node + 1].x += 1;
			lazy[2 * node + 1].y += L_I + ((s + 1) >> 1);
		}

		return ret;
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return ret = update(L, start, mid, cmd_a, cmd_b) + update(R, mid + 1, end, cmd_a, cmd_b);
}

ll sum(ll node, ll start, ll end, ll cmd_a, ll cmd_b)
{
	propagate(node, start, end);

	if (cmd_a > end || cmd_b < start)
		return 0;

	if (cmd_a <= start && end <= cmd_b)
		return seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	return sum(L, start, mid, cmd_a, cmd_b) + sum(R, mid + 1, end, cmd_a, cmd_b);
}

int main()
{
	fastio;

	cin >> N;

	lazy_init();

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];
	
	Init(1, 0, N - 1);

	cin >> M;

	for (ll i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b;

		if (a == 1)
		{
			cin >> c;

			update(1, 0, N - 1, b - 1, c - 1);
		}
		else
			cout << sum(1, 0, N - 1, b - 1, b - 1) << '\n';
	}
}