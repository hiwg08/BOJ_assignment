#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N;

ll pre_sum[3002][3002]{ 0 };

ll DP[3002]{ 0 };

void input()
{
	cin >> N;

	for (ll i = 1, a; i <= N; i++)
	{
		while (true)
		{
			cin >> a;

			if (a == 0)
				break;

			if (a < i)
				continue;

			pre_sum[i][a]++;
		}
	}

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			pre_sum[i][j] += pre_sum[i][j - 1];
		// 가로로 누적 합
	}

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = 1; j <= N; j++)
			pre_sum[i][j] += pre_sum[i - 1][j];
	}
}

ll calc_1(ll a, ll b)
{
	return pre_sum[b][b] - pre_sum[b][a - 1] - pre_sum[a - 1][b] + pre_sum[a - 1][a - 1];
}

ll calc_2(ll nx, ll ny, ll sx, ll sy)
{
	return pre_sum[sx][sy] - pre_sum[nx - 1][sy] - pre_sum[sx][ny - 1] + pre_sum[nx - 1][ny - 1];
}

ll trace[3001]{ 0 };

ll solve(ll Idx)
{
	if (Idx >= N + 1)
		return 0;
	
	ll& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	ll sum = 0;
	
	for (ll i = Idx; i <= N; i++)
	{
		sum += (i - Idx);

		ll group_member = calc_1(Idx, i);

		ll distance_per = calc_2(Idx, i + 1, i, N);

		ll diff = sum - group_member;

		if (ret >= solve(i + 1) + diff + distance_per)
		{
			ret = solve(i + 1) + diff + distance_per;

			trace[Idx] = i + 1;
		}
	}

	return ret;
}

vector<ll> ans;

void reconstruct(ll Idx)
{
	if (Idx >= N + 1)
		return;

	ans.push_back(trace[Idx] - Idx);

	reconstruct(trace[Idx]);
}

int main()
{
	fastio;

	input();

	memset(DP, -1, sizeof(DP));

	cout << solve(1) << '\n';

	reconstruct(1);

	cout << (ll)ans.size() << " ";
	
	for (auto e : ans)
		cout << e << " ";
}