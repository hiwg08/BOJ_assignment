#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second

using namespace std;

ll N, M;

ll Arr[31][31]{ 0 };

ll pre_sum_g[31][31]{ 0 };

ll pre_sum_s[31][31]{ 0 };

bool vis[31][31]{ 0 };

void init()
{
	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			pre_sum_g[i][j] = Arr[i][j] + pre_sum_g[i][j - 1];
	}

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			pre_sum_s[j][i] = pre_sum_g[j][i] + pre_sum_s[j - 1][i];
	}
}

ll calc(ll x1, ll y1, ll x2, ll y2)
{
	return pre_sum_s[x2][y2] - pre_sum_s[x1 - 1][y2] - pre_sum_s[x2][y1 - 1] + pre_sum_s[x1 - 1][y1 - 1];
}

struct comp
{
	ll K;
	ll x1, y1, x2, y2;
};

bool check(ll x1, ll y1, ll x2, ll y2)
{
	bool ret = true;

	for (ll i = y1; i <= y2; i++)
	{
		if (vis[x1][i] || vis[x2][i])
			ret = false;
	}
	for (ll i = x1; i <= x2; i++)
	{
		if (vis[i][y1] || vis[i][y2])
			ret = false;
	}

	return ret;
}

void monge(ll x1, ll y1, ll x2, ll y2, bool q)
{
	for (ll i = y1; i <= y2; i++)
		vis[x1][i] = q, vis[x2][i] = q;
	for (ll i = x1; i <= x2; i++)
		vis[i][y1] = q, vis[i][y2] = q;
}

vector<comp> ans;

void solve(ll cnt)
{
	if (cnt == M)
	{
		for (auto& e : ans)
			cout << e.K << " " << e.x1 << " " << e.y1 << " " << e.x2 << " " << e.y2 << '\n';

		exit(0);
	}

	ll min_r = LLONG_MIN;

	for (ll i = 2; i <= N - 1; i++)
	{
		for (ll j = 2; j <= N - 1; j++)
		{
			for (ll k = 1; k <= N - i; k++)
			{
				for (ll q = 1; q <= N - j; q++)
				{
					ll n1 = k, n2 = q, n3 = i + k, n4 = j + q;

					if (!check(n1, n2, n3, n4))
						continue;

					ll outer = calc(n1, n2, n3, n4);

					ll inter = calc(n1 + 1, n2 + 1, n3 - 1, n4 - 1);

					ll res = outer - inter;

					min_r = max(min_r, res);
				}
			}
		}
	}

	for (ll i = 2; i <= N - 1; i++)
	{
		for (ll j = 2; j <= N - 1; j++)
		{
			for (ll k = 1; k <= N - i; k++)
			{
				for (ll q = 1; q <= N - j; q++)
				{
					ll n1 = k, n2 = q, n3 = i + k, n4 = j + q;

					if (!check(n1, n2, n3, n4))
						continue;

					ll outer = calc(n1, n2, n3, n4);

					ll inter = calc(n1 + 1, n2 + 1, n3 - 1, n4 - 1);

					ll res = outer - inter;

					if (res == min_r)
					{
						monge(n1, n2, n3, n4, true);

						ans.push_back({min_r, n1, n2, n3, n4});

						solve(cnt + 1);

						ans.pop_back();

						monge(n1, n2, n3, n4, false);
					}
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			cin >> Arr[i][j];
	}

	init();

	solve(0);

	cout << 0;
}