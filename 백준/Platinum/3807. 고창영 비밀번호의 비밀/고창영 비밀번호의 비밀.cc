#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e9 + 7)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, ans;

vector<pll> V;

ll dd[2]{ 0 }, ss[2]{ 0 };

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if ((pows & 1) == 1)
	{
		ll T1 = dev_con(params, pows - 1);

		mul_mod(T1, params);

		return T1;
	}

	ll T1 = dev_con(params, pows >> 1);

	mul_mod(T1, T1);

	return T1;
}

void precomp()
{
	memset(dd, 0, sizeof(dd));

	memset(ss, 0, sizeof(ss));

	if (N == 1)
	{
		ll L1 = dev_con(V[0].x, V[0].y);

		ll R1 = 1;

		for (ll i = 0; i <= V[0].y; i++)
		{
			add_mod(ans, R1);
			add_mod(ans, L1);
			mul_mod(R1, V[0].x);
		}

		return;
	}

	ll L2 = dev_con(V[N - 2].x, V[N - 2].y);

	ll R2 = dev_con(V[N - 1].x, V[N - 1].y);

	ll L1 = 1;

	for (ll i = 0; i <= V[N - 2].y; i++)
	{
		ll R1 = 1;

		for (ll j = 0; j <= V[N - 1].y; j++)
		{
			if (L1 == L2 && R1 == R2)
			{
				ll Q = L1, W = L2;
				mul_mod(Q, R1);
				mul_mod(W, R2);

				add_mod(dd[0], Q);
				add_mod(dd[1], W);
			}

			else if (L1 != L2 && R1 != R2)
			{
				ll Q = L1, W = L2;
				mul_mod(Q, R1);
				mul_mod(W, R2);

				add_mod(ss[0], Q);
				add_mod(ss[1], W);

				Q = L1, W = L2;
				mul_mod(Q, R2);
				mul_mod(W, R1);

				add_mod(ss[0], Q);
				add_mod(ss[1], W);
			}
			else 
			{
				ll Q = L1, W = L2;
				mul_mod(Q, R1);
				mul_mod(W, R2);

				add_mod(ss[0], Q);
				add_mod(ss[1], W);
			}
			
			mul_mod(R1, V[N - 1].x);
		}

		mul_mod(L1, V[N - 2].x);
	}

	for (ll i = N - 3; i >= 0; i--)
	{
		ll t_dd[2]{ 0 }, t_ss[2]{ 0 };

		ll L2 = dev_con(V[i].x, V[i].y);

		ll L1 = 1;

		for (ll j = 0; j <= V[i].y; j++)
		{
			if (L1 == L2 && dd[0] == dd[1])
			{
				ll Q = L1, W = L2;
				mul_mod(Q, dd[0]);
				mul_mod(W, dd[1]);

				add_mod(t_dd[0], Q);
				add_mod(t_dd[1], W);
			}
			else if (L1 != L2 && dd[0] != dd[1])
			{
				ll Q = L1, W = L2;
				mul_mod(Q, dd[0]);
				mul_mod(W, dd[1]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);

				Q = L1, W = L2;
				mul_mod(Q, dd[1]);
				mul_mod(W, dd[0]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);
			}
			else
			{
				ll Q = L1, W = L2;
				mul_mod(Q, dd[0]);
				mul_mod(W, dd[1]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);
			}

			if (L1 == L2 && ss[0] == ss[1])
			{
				ll Q = L1, W = L2;
				mul_mod(Q, ss[0]);
				mul_mod(W, ss[1]);

				add_mod(t_dd[0], Q);
				add_mod(t_dd[1], W);
			}
			else if (L1 != L2 && ss[0] != ss[1])
			{
				ll Q = L1, W = L2;
				mul_mod(Q, ss[0]);
				mul_mod(W, ss[1]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);

				Q = L1, W = L2;
				mul_mod(Q, ss[1]);
				mul_mod(W, ss[0]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);
			}
			else
			{
				ll Q = L1, W = L2;
				mul_mod(Q, ss[0]);
				mul_mod(W, ss[1]);

				add_mod(t_ss[0], Q);
				add_mod(t_ss[1], W);
			}

			mul_mod(L1, V[i].x);
		}

		dd[0] = t_dd[0], dd[1] = t_dd[1];
		ss[0] = t_ss[0], ss[1] = t_ss[1];
	}

	add_mod(ans, dd[0]);
	add_mod(ans, dd[1]);
	add_mod(ans, ss[0]);
	add_mod(ans, ss[1]);
}

int main()
{
	fastio;

	ll T; cin >> T;

	while (T--)
	{
		ans = 0;

		V.clear();
		vector<pll>().swap(V);

		cin >> N;

		for (ll i = 0, a, b; i < N; i++)
		{
			cin >> a >> b;
			V.push_back({ a, b });
		}

		precomp();

		cout << ans << '\n';
	}
}