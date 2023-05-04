#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1000000007)

using namespace std;

ll DP[51][51]{ 0 };

ll N, K, total;

vector<ll> Tree[51];

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void mul_mod(ll& ret, ll params)
{
	ret *= params;
	ret %= MOD;
}

void init()
{
	for (ll i = 0; i <= 50; i++)
		DP[i][0] = 1;
}

void solve(ll Idx, ll before)
{
	bool chk = false;

	ll pre_node = -1;

	for (auto e : Tree[Idx]) 
	{
		if (e == before)
			continue;

		solve(e, Idx);
			
		if (!chk)
			chk = true;
		else
		{
			ll tmp[51]{ 0 };

			for (ll i = 1; i <= K; i++)
			{
				for (ll j = 0; j <= i; j++)
				{
					ll nx = j, ny = i - j;

					ll A = DP[pre_node][nx];

					mul_mod(A, DP[e][ny]);

					add_mod(tmp[i], A);
				}
			}

			for (ll i = 1; i <= K; i++)
				DP[e][i] = tmp[i];
		}
		pre_node = e;
	}

	if (pre_node != -1)
	{
		for (ll i = 1; i <= K; i++)
			DP[Idx][i] = DP[pre_node][i - 1];
	}
	else
		DP[Idx][1] = 1;

	add_mod(total, DP[Idx][K]);
	// 여기서 최종 갱신?
}

int main()
{
	cin >> N >> K;

	for (ll i = 0, a, b; i < N - 1; i++)
	{
		cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
	}

	init();

	solve(1, -1);

	cout << total;
}