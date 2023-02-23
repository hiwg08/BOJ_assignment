#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MOD (ll)(1e9 + 7)
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, Arr[100001]{ 0 };

ll seg[100001 * 4]{ 0 };

pll lazy[100001 * 4];

void a_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void m_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void lazy_init()
{
	for (ll i = 0; i <= 400003; i++)
		lazy[i] = { 1, 0 };
}

ll Init(ll node, ll start, ll end)
{
	ll& ret = seg[node];

	if (start == end)
		return ret = Arr[start];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	ll le = Init(L, start, mid), ri = Init(R, mid + 1, end), A = 0;

	a_mod(A, le); a_mod(A, ri);

	return ret = A;
}

void propagate(ll node, ll start, ll end)
{
	if (lazy[node].x != 1 || lazy[node].y != 0)
	{
		ll L = lazy[node].x; ll R = lazy[node].y, s = end - start + 1;

		m_mod(s, R);

		m_mod(seg[node], L); a_mod(seg[node], s);

		if (start != end)
		{
			m_mod(lazy[2 * node].x, lazy[node].x);
			m_mod(lazy[2 * node].y, lazy[node].x);
			a_mod(lazy[2 * node].y, lazy[node].y);

			m_mod(lazy[2 * node + 1].x, lazy[node].x);
			m_mod(lazy[2 * node + 1].y, lazy[node].x);
			a_mod(lazy[2 * node + 1].y, lazy[node].y);
		}

		lazy[node] = { 1, 0 };
	}
}

ll update(ll node, ll start, ll end, ll cmd_a, ll cmd_b, ll params, ll chk)
{
	propagate(node, start, end);

	ll& ret = seg[node];

	if (cmd_a > end || cmd_b < start)
		return ret;

	if (cmd_a <= start && end <= cmd_b)
	{
		ll s = end - start + 1, e = s;

		if (chk == 1)
		{
			m_mod(e, params);
			a_mod(ret, e);

			if (start != end)
			{
				a_mod(lazy[2 * node].y, params);
				a_mod(lazy[2 * node + 1].y, params);
			}
		}
		else if (chk == 2)
		{
			m_mod(ret, params);

			if (start != end)
			{
				m_mod(lazy[2 * node].x, params);
				m_mod(lazy[2 * node].y, params);
				m_mod(lazy[2 * node + 1].x, params);
				m_mod(lazy[2 * node + 1].y, params);
			}
		}
		else
		{
			m_mod(e, params);

			if (start != end)
			{
				lazy[2 * node] = { 0, params };
				lazy[2 * node + 1] = { 0, params };
			}

			ret = e;
		}

		return ret;
	}

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	ll le = update(L, start, mid, cmd_a, cmd_b, params, chk), ri = update(R, mid + 1, end, cmd_a, cmd_b, params, chk), A = 0;

	a_mod(A, le); a_mod(A, ri);

	return ret = A;
}

ll sum(ll node, ll start, ll end, ll cmd_a, ll cmd_b)
{
	propagate(node, start, end);

	if (cmd_a > end || cmd_b < start)
		return 0;

	if (cmd_a <= start && end <= cmd_b)
		return seg[node];

	ll L = 2 * node, R = L + 1, mid = (start + end) >> 1;

	ll le = sum(L, start, mid, cmd_a, cmd_b), ri = sum(R, mid + 1, end, cmd_a, cmd_b), A = 0;

	a_mod(A, le); a_mod(A, ri);

	return A;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	Init(1, 0, N - 1);

	cin >> M;

	lazy_init();

	for (ll i = 0, a, b, c, d; i < M; i++)
	{
		cin >> a >> b >> c;

		if (a == 1 || a == 2 || a == 3)
		{
			cin >> d;

			update(1, 0, N - 1, b - 1, c - 1, d, a);
		}
		if (a == 4)
			cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
	}
}