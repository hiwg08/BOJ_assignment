#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll N;

ll mask = 0;

ll stt[51]{ 0 }, inn[51]{ 0 }, pnt[51]{ 0 };

ll DP[1001][1001]{ 0 };

ll solve(ll L, ll R) // 현재 스탯이 각각 L, R일 때, 깰 수 있는 퀘스트의 수의 '최댓값'
{
	ll& ret = DP[L][R];

	if (ret != -1)
		return ret;

	ll nu = 0, pre_mask = 0, score = 0;

	for (ll i = 0; i < N; i++)
	{
		if (stt[i] <= L || inn[i] <= R)
		{
			if (!(mask & (o << i)))
			{
				pre_mask |= (o << i);
				score += pnt[i];
			}
			nu++;
		}
	}

	ret = nu;

	score = min(score, (ll)2000);

	for (ll i = score; i >= 0; i--)
	{
		ll q = i, w = score - i;

		mask |= pre_mask;

		ret = max(ret, solve(min((ll)1000, L + q), min((ll)1000, R + w)));

		mask ^= pre_mask;
	}

	return ret;
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> stt[i] >> inn[i] >> pnt[i];

	memset(DP, -1, sizeof(DP));

	cout << solve(1, 1);
}