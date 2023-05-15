#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll N, K, zari, total = LLONG_MAX;

ll DP[20][1 << 11][2]{ 0 }; 

ll mask[20]{ 0 };

ll solve(ll Idx, ll bit, ll flag, ll num)
{
	if (Idx >= zari) // 얘는 끝까지 다 본 경우
	{
		if ((ll)__builtin_popcount(bit) == K) // 그냥 여기서 계산하는 게 마음 편할 듯?
		{
			total = min(total, num);
			return 1;
		}
		return 0;
	}
		
	ll& ret = DP[Idx][bit][flag];

	if (ret != -1)
		return ret;

	ll start = 0;

	if (!flag)
		start = mask[Idx];

	for (ll i = start; i <= 9; i++) // 9가 끝.
	{
		if (!flag)
		{
			if (solve(Idx + 1, bit | (o << i), i != mask[Idx], num * 10 + i) == 1)
				return ret = 1;
		}
		else
		{
			if (solve(Idx + 1, bit | (o << i), 1, num * 10 + i) == 1)
				return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	string S = to_string(N);

	ll size_to = (ll)(S.size());

	zari = max(size_to, K);

	if (size_to >= K)
	{
		for (ll i = 0; i < (ll)S.length(); i++)
			mask[i] = (ll)(S[i] - '0');
	}
	else
	{
		memset(mask, 0, sizeof(mask));

		mask[0] = 1;
	}

	if (solve(0, 0, 0, 0) == 1)
	{
		cout << total;
		exit(0);
	}
	
	zari++;

	memset(DP, -1, sizeof(DP));

	memset(mask, 0, sizeof(mask));

	mask[0] = 1;

	if (solve(0, 0, 0, 0) == 1)
		cout << total;
}