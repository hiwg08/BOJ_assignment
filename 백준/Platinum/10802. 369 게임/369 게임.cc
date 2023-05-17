#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(20150523)

using namespace std;

string A, B;

struct info
{
	ll r[3]{ 0 };
	ll pa = 0;
	ll sub[3]{ 0 };
};

ll precomp[100001]{ 0 };

// sub에는 3, 6, 9 AND 3의 배수인 놈이 들어감

// pa는 3, 6, 9가 들어가는 놈이 들어감

info DP[100001][10]{ 0 };

void at_()
{
	precomp[1] = 10;

	for (ll i = 2; i <= 100000; i++)
		precomp[i] = ((precomp[i - 1] % MOD) * 10) % MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void sub_mod(ll& ret, ll params)
{
	ret = (ret - params + MOD) % MOD;
}

ll chtoi(char c)
{
	return (ll)(c - '0');
}

void init()
{
	DP[1][1].r[0] = 1;
	DP[1][1].r[1] = 1;
	DP[1][1].r[2] = 0;
	DP[1][1].pa = 0;
	DP[1][1].sub[0] = 0;
	DP[1][1].sub[1] = 0;
	DP[1][1].sub[2] = 0;

	DP[1][2].r[0] = 1;
	DP[1][2].r[1] = 1;
	DP[1][2].r[2] = 1;
	DP[1][2].pa = 0;
	DP[1][2].sub[0] = 0;
	DP[1][2].sub[1] = 0;
	DP[1][2].sub[2] = 0;

	DP[1][3].r[0] = 2;
	DP[1][3].r[1] = 1;
	DP[1][3].r[2] = 1;
	DP[1][3].pa = 1;
	DP[1][3].sub[0] = 1;
	DP[1][3].sub[1] = 0;
	DP[1][3].sub[2] = 0;

	DP[1][4].r[0] = 2;
	DP[1][4].r[1] = 2;
	DP[1][4].r[2] = 1;
	DP[1][4].pa = 1;
	DP[1][4].sub[0] = 1;
	DP[1][4].sub[1] = 0;
	DP[1][4].sub[2] = 0;

	DP[1][5].r[0] = 2;
	DP[1][5].r[1] = 2;
	DP[1][5].r[2] = 2;
	DP[1][5].pa = 1;
	DP[1][5].sub[0] = 1;
	DP[1][5].sub[1] = 0;
	DP[1][5].sub[2] = 0;

	DP[1][6].r[0] = 3;
	DP[1][6].r[1] = 2;
	DP[1][6].r[2] = 2;
	DP[1][6].pa = 2;
	DP[1][6].sub[0] = 2;
	DP[1][6].sub[1] = 0;
	DP[1][6].sub[2] = 0;

	DP[1][7].r[0] = 3;
	DP[1][7].r[1] = 3;
	DP[1][7].r[2] = 2;
	DP[1][7].pa = 2;
	DP[1][7].sub[0] = 2;
	DP[1][7].sub[1] = 0;
	DP[1][7].sub[2] = 0;

	DP[1][8].r[0] = 3;
	DP[1][8].r[1] = 3;
	DP[1][8].r[2] = 3;
	DP[1][8].pa = 1;
	DP[1][8].sub[0] = 2;
	DP[1][8].sub[1] = 0;
	DP[1][8].sub[2] = 0;

	DP[1][9].r[0] = 4;
	DP[1][9].r[1] = 3;
	DP[1][9].r[2] = 3;
	DP[1][9].pa = 3;
	DP[1][9].sub[0] = 3;
	DP[1][9].sub[1] = 0;
	DP[1][9].sub[2] = 0;

	for (ll i = 0; i < 3; i++)
		DP[1][0].r[i] = 3;

	DP[1][0].r[0] = 4;

	DP[1][0].pa = 3;

	DP[1][0].sub[0] = 3;

	for (ll i = 2; i <= 100000; i++)
	{
		for (ll j = 0; j < 3; j++)
			DP[i][0].r[j] = DP[i - 1][0].r[j];

		for (ll j = 0; j < 3; j++)
			DP[i][0].sub[j] = DP[i - 1][0].sub[j];

		DP[i][0].pa = DP[i - 1][0].pa;

		for (ll j = 1; j <= 9; j++)
		{
			ll remain = j % 3;

			for (ll k = 0; k < 3; k++)
				DP[i][j].r[(k + remain) % 3] = DP[i - 1][0].r[k];

			if (remain == 0)
			{
				for (ll k = 0; k < 3; k++)
					DP[i][j].sub[k] = DP[i - 1][0].r[k];

				DP[i][j].pa = precomp[i - 1];
			}
			else
			{
				for (ll k = 0; k < 3; k++)
					DP[i][j].sub[(k + remain) % 3] = DP[i - 1][0].sub[k];
				DP[i][j].pa = DP[i - 1][0].pa;
			}

			for (ll k = 0; k < 3; k++)
			{
				add_mod(DP[i][j].r[k], DP[i][j - 1].r[k]);
				add_mod(DP[i][j].sub[k], DP[i][j - 1].sub[k]);
			}
			add_mod(DP[i][j].pa, DP[i][j - 1].pa);
		}

		for (ll k = 0; k < 3; k++)
		{
			DP[i][0].r[k] = DP[i][9].r[k];
			DP[i][0].sub[k] = DP[i][9].sub[k];
		}

		DP[i][0].pa = DP[i][9].pa;
	}
}

ll solve(string B)
{
	ll nu = 0;

	ll total = 0;

	bool flag = false;

	for (ll i = 0; i < (ll)B.length(); i++)
	{
		ll zari = (ll)B.length() - i;

		ll Idx = chtoi(B[i]) - 1;

		if (zari == 1)
		{
			for (ll k = 0; k <= chtoi(B[i]); k++)
			{
				if (flag)
				{
					add_mod(total, 1);
					continue;
				}
				if (k != 0 && (k % 3) == 0)
				{
					add_mod(total, 1);
					continue;
				}

				if ((ll)B.length() > 1 && (nu + k) % 3 == 0)
				{
					add_mod(total, 1);
					continue;
				}
			}
			break;
		}

		if (flag)
		{
			ll comp = 0;

			for (ll j = i; j < (ll)B.length(); j++)
				comp = (comp * 10 + chtoi(B[j])) % MOD;

			add_mod(total, 1);

			add_mod(total, comp);
			break;
		}

		if (chtoi(B[i]) == 1)
		{
			ll A = DP[zari - 1][9].r[(3 - nu) % 3];

			if (i == 0)
				sub_mod(A, 1);

			add_mod(A, DP[zari - 1][9].pa);
			sub_mod(A, DP[zari - 1][9].sub[(3 - nu) % 3]);
			add_mod(total, A);
		}
		else if (chtoi(B[i]) > 1)
		{
			ll A = DP[zari][Idx].r[(3 - nu) % 3];

			if (i == 0)
				sub_mod(A, 1);

			add_mod(A, DP[zari][Idx].pa);
			sub_mod(A, DP[zari][Idx].sub[(3 - nu) % 3]);
			add_mod(total, A);
		}

		nu = (nu + chtoi(B[i])) % 3;

		if (chtoi(B[i]) != 0 && chtoi(B[i]) % 3 == 0)
			flag = true;
	}

	return total;
}

int main()
{
	at_();

	init();

	cin >> A >> B;

	ll ans = solve(B);

	sub_mod(ans, solve(A));

	ll nu = 0;

	for (ll i = 0; i < (ll)A.length(); i++)
	{
		nu += chtoi(A[i]);

		if (chtoi(A[i]) != 0 && chtoi(A[i]) % 3 == 0)
		{
			nu = -1;
			break;
		}
	}

	if (nu == -1 || (nu % 3) == 0)
		add_mod(ans, 1);

	cout << ans;
}