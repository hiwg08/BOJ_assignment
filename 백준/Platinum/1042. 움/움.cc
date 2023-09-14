#include <bits/stdc++.h>
#define ll long long
#define o (ll)1
#define MOD (ll)(1e9 + 7)
#define x first
#define y second

using namespace std;

ll M;

string S;

ll pos[4][2501]{ 0 };

ll dp[2501]{ 0 };

vector<pair<string, string>> V;

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll ch_in(char c)
{
	if (c == 'A')
		return 0;
	if (c == 'C')
		return 1;
	if (c == 'G')
		return 2;
	return 3;
}

void precomp()
{
	for (ll i = 0; i < (ll)S.length(); i++)
	{
		ll vis = 0;

		for (ll j = i; j < (ll)S.length(); j++)
		{
			if (vis == 15)
				break;

			ll a = ch_in(S[j]);

			if ((vis & (o << a)) == 0)
			{
				vis |= o << a;
				pos[a][i] = j;
			}
		}
	}
}

ll find_dna(ll Idx, string params)
{
	for (ll i = 0; i < 3; i++)
	{
		if (Idx >= (ll)S.length())
			return -1;
		if (pos[ch_in(params[i])][Idx] == -1)
			return -1;

		Idx = pos[ch_in(params[i])][Idx] + 1;
	}

	return Idx;
}

ll solve(ll Idx)
{
	if (Idx >= (ll)S.length())
		return 0;

	ll& ret = dp[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	string chk = ".";

	ll fina = LLONG_MAX;

	for (ll i = 0; i < M; i++)
	{
		if (chk != V[i].y)
		{
			if (chk != ".")
			{
				if (fina != LLONG_MAX)
				{
					add_mod(ret, 1);
					add_mod(ret, solve(fina));
				}
			}

			fina = LLONG_MAX;
			chk = V[i].y;
		}

		ll is_exist = find_dna(Idx, V[i].x);

		if (is_exist != -1)
			fina = min(fina, is_exist);
	}

	if (fina != LLONG_MAX)
	{
		add_mod(ret, 1);
		add_mod(ret, solve(fina));
	}

	return ret;
}

int main()
{
	cin >> S;

	cin >> M; V.resize(M);
	
	for (auto& iv : V)
		cin >> iv.x >> iv.y;

	sort(V.begin(), V.end(), [&](pair<string, string> a, pair<string, string> b) {
		return a.y < b.y;
	});

	memset(pos, -1, sizeof(pos));

	memset(dp, -1, sizeof(dp));

	precomp();

	cout << solve(0);
}