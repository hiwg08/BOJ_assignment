#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007

using namespace std;

ll T, N, D, part[101][21][21]{ 0 }, cycle[101][21][21]{ 0 };

vector<vector<ll>> Ans;

void make_cycle()
{
	for (ll i = 2; i <= T; i++)
	{
		for (ll j = 1; j <= N; j++)
		{
			for (ll k = 1; k <= N; k++)
			{
				for (ll q = 1; q <= N; q++)
					cycle[i][j][k] = (cycle[i][j][k] % MOD) + ((cycle[i - 1][j][q] % MOD) * (part[i][q][k] % MOD)) % MOD;
			}
		}
	}
}

vector<vector<ll>> dev_con(ll pows)
{
	vector<vector<ll>> V(N + 1, vector<ll>(N + 1, 0));

	if (pows == 0)
	{
		for (ll i = 1; i <= N; i++)
		{
			for (ll j = 1; j <= N; j++)
				i == j ? V[i][j] = 1 : V[i][j] = 0;
		}
		return V;
	}

	vector<vector<ll>> T1;

	if (pows % 2 == 0)
	{
		T1 = dev_con(pows / 2);

		for (ll i = 1; i <= N; i++)
		{
			for (ll j = 1; j <= N; j++)
			{
				for (ll k = 1; k <= N; k++)
					V[i][j] = ((V[i][j] % MOD) + (((T1[i][k] % MOD) * (T1[k][j] % MOD)) % MOD)) % MOD;
			}
		}

		return V;
	}

	T1 = dev_con(pows - 1);

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
		{
			for (ll k = 1; k <= N; k++)
				V[i][j] = ((V[i][j] % MOD) + (((cycle[T][i][k] % MOD) * (T1[k][j] % MOD)) % MOD)) % MOD;
		}
	}

	return V;
}

int main()
{
	fastio;

	cin >> T >> N >> D;

	for (ll i = 1, a; i <= T; i++)
	{
		cin >> a;

		for (ll j = 0, b, c, d; j < a; j++)
		{
			cin >> b >> c >> d;
			part[i][b][c] = d;

			if (i == 1)
				cycle[i][b][c] = d;
		}
	}

	make_cycle();

	ll expo = D / T, remain = D % T;

	Ans = dev_con(expo);

	if (remain > 0)
	{
		for (ll i = 1; i <= N; i++)
		{
			for (ll j = 1; j <= N; j++)
			{
				ll Tmp = 0;
				for (ll k = 1; k <= N; k++)
					Tmp = ((Tmp % MOD) + (((Ans[i][k] % MOD) * (cycle[remain][k][j] % MOD)) % MOD)) % MOD;
				cout << Tmp << " ";
			}
			cout << '\n';
		}
		exit(0);
	}

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			cout << Ans[i][j] << " ";
		cout << '\n';
	}
}