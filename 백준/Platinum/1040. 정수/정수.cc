#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll N, K, zari, total = LLONG_MAX;

ll mask_1[19]{ 0 };

ll DP[19][1 << 11][2]{ 0 };

ll solve(ll Idx, ll bit, ll flag, ll num)
{	
	if (Idx >= zari)
	{
		if ((ll)__builtin_popcount(bit) == K)
		{
			total = min(total, num);
			return 1;
		}
		return 0;
	}

	ll& ret = DP[Idx][bit][flag];

	if (ret != -1)
		return ret;

	ret = 0;

	if (flag == 0)
	{
		for (ll i = mask_1[Idx]; i <= 9; i++)
		{
			if (solve(Idx + 1, bit | (o << i), i != mask_1[Idx], num * 10 + i))
				return ret = 1;
		}
	}
	else
	{
		for (ll i = 0; i <= 9; i++)
		{
			if (solve(Idx + 1, bit | (o << i), 1, num * 10 + i))
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	string T = to_string(N);

	zari = max((ll)T.length(), K);

	if ((ll)T.length() >= K)
	{
		for (ll i = 0; i < (ll)T.length(); i++)
			mask_1[i] = (ll)(T[i] - '0');
	}
	else
	{
		memset(mask_1, 0, sizeof(mask_1));

		mask_1[0] = 1;
	}

	if (solve(0, 0, 0, 0) == 1)
	{
		cout << total;
		exit(0);
	}

	total = LLONG_MAX;

	zari++;

	memset(DP, -1, sizeof(DP));

	memset(mask_1, 0, sizeof(mask_1));

	mask_1[0] = 1;

	if (solve(0, 0, 0, 0) == 1)
		cout << total;
}