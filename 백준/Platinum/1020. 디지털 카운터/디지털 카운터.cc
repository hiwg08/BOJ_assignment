#include <bits/stdc++.h>
#define ll long long

using namespace std;

string S;

ll total, ans = LLONG_MAX, zari;

ll DP[16][120][2]{ 0 };

ll blocks[10]{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };

ll numb[16]{ 0 };

ll precomp[16]{ 0 };

ll solve(ll Idx, ll sum, ll flag) // flag가 1이면 이상, 0이면 초과.
{
	if (Idx >= (ll)S.length())
	{
		if (sum == total)
			return 0;
		
		return -2;
	}

	ll& ret = DP[Idx][sum][flag];

	if (ret != -1)
		return ret;

	ll conv = (ll)(S[Idx] - '0');

	ll start = conv, min_diff = LLONG_MAX;

	if (!flag)
		start++;

	ret = LLONG_MAX;

	for (ll i = start; i <= 9; i++) // 여기는 자율 
	{
		ll T = solve(Idx + 1, sum + blocks[i], 1);

		if (!(T == -2 || T == LLONG_MAX))
		{
			ll mid = T * 10 + i;

			ll diff = mid - numb[Idx];

			if (numb[Idx] == mid)
			{
				if (!flag)
					diff = precomp[zari - Idx];
				else
					diff = 0;
			}

			if (numb[Idx] > mid)
				diff = mid - numb[Idx] + precomp[zari - Idx];

			if (min_diff > diff)
			{
				min_diff = diff;

				ret = mid;
			}
		}
	}

	for (ll i = 0; i <= start - 1; i++) // 여기는 '반드시' 수를 올려야 한다.
	{
		ll T = solve(Idx + 1, sum + blocks[i], 0);

		if (!(T == -2 || T == LLONG_MAX))
		{
			ll mid = T * 10 + i;

			ll diff = mid - numb[Idx];

			if (numb[Idx] == mid)
			{
				if (!flag)
					diff = precomp[zari - Idx];
				else
					diff = 0;
			}

			if (numb[Idx] > mid)
				diff = mid - numb[Idx] + precomp[zari - Idx];

			if (min_diff > diff)
			{
				min_diff = diff;

				ret = mid;
			}
		}
	}

	return ret;
}

void init()
{
	ll Idx = 0;

	string cmp = S;

	while (!cmp.empty())
	{
		numb[Idx++] = stoll(cmp);
		cmp.pop_back();
	}

	precomp[0] = 1;

	for (ll i = 1; i <= 15; i++)
		precomp[i] = precomp[i - 1] * 10;
}

int main()
{
	cin >> S;

	init();

	zari = (ll)S.length();

	for (auto e : S)
		total += blocks[(ll)(e - '0')];

	memset(DP, -1, sizeof(DP));

	reverse(S.begin(), S.end());

	ll ans = solve(0, 0, 0);

	if (numb[0] < ans)
		cout << ans - numb[0];
	else
		cout << ans - numb[0] + precomp[zari];
}