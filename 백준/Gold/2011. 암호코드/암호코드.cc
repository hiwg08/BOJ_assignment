#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(1e6)

using namespace std;

ll DP[5001]{ 0 };

string S;

ll N;

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll Idx)
{
	if (Idx >= N)
		return 1;

	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 0;

	char a = '.', b = '.';

	if (Idx < N)
		a = S[Idx];

	if (Idx + 1 < N)
		b = S[Idx + 1];

	if (a == '1' || a == '2')
	{
		add_mod(ret, solve(Idx + 1));

		if (b != '.')
		{
			if (a == '1')
				add_mod(ret, solve(Idx + 2));
			else
			{
				if (b >= '0' && b <= '6')
					add_mod(ret, solve(Idx + 2));
			}
		}
	}
	else if (a >= '3' && a <= '9')
		add_mod(ret, solve(Idx + 1));

	return ret;
}

int main()
{
	cin >> S;

	N = (ll)S.size();

	memset(DP, -1, sizeof(DP));

	cout << solve(0);
}