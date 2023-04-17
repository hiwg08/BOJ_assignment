#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(100030001)

using namespace std;

ll N, M;

ll DP[301][301][2]{ 0 };

// dp[L][R][state] : 현재 소유하고 있는 노드의 개수(L), 현재 트리의 높이 (R), 현재 상태가 state일 때 만들 수 있는 트리의 경우의 수
// state : 0 --> 현재 소유하고 있는 노드의 개수(L)로 정확히 R의 높이만큼 채울 수 없는 경우의 수
// ex. dp[4][4][0] = dp[4][3][1] + dp[4][2][1] + dp[4][1][1];
// 그러나 실제로 이렇게 하면 꽤 꼬이므로, 구현의 편리함을 위해 dp[4][4][1]을 추가로 더해줬다.

// state : 1 --> 현재 소유하고 있는 노드의 개수(L)로 정확히 R의 높이만큼 채울 수 있는 경우의 수
// L < R, 즉 현재 갖고 있는 노드의 개수보다 '앞으로' 채워야 하는 높이가 더 크면 **절 대 로** 정확히 R만큼 트리를 만들 수 없으니
// 이 점은 예외로 점프시키자.

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

ll solve(ll size, ll height, ll state)
{
	if (height <= 0) // 기저 조건1. 현재 높이가 0 이하일 때 --> 애당초 트리가 생성될 수가 없음
		return 0;

	if (size == 1) // 기저 조건2. 앞으로 채워야 하는 노드의 개수(size)가 1일 때 
	{
		if (height == 1)
			return 1;
		return 0;
	}
          // Q : 왜 state가 0인 경우는 체크 안 해주나?
	// A : **** state가 0인 경우는 곧 state가 1인 경우의 '합'이기 때문에 **** 현재의 기저 조건으로도 충분하다.

	ll& ret = DP[size][height][state];

	if (ret != -1)
		return ret;

	if (state == 0)
	{
		ll nu = 0;

		for (ll i = height; i >= 1; i--)
			add_mod(nu, solve(size, i, 1));

		return ret = nu;
	} // 따라서 위에 있는 설명과 같이, state가 0일 때는 state가 1인 경우들의 '누적합'을 구하면 된다.

	ret = 0;

	for (ll i = size - 1; i >= 0; i--)
	{
		ll L = i, R = size - 1 - i;

		if (L == 0)
		{
			ll R1 = 0;

			if (R >= height - 1)
				R1 = solve(R, height - 1, 1);
                             // R이 height - 1보다 무조건 크거나 같아야지만 정확하게 트리를 만들 수 있다.
                             // 물론 R이 height - 1보다 크기만 하면 정확하게 트리를 만들 수 없지만, height <= 0이라는 기저 조건때문에 지장은 없다.

			add_mod(ret, R1);
		}
		else if (R == 0)
		{
			ll L1 = 0;

			if (L >= height - 1)
				L1 = solve(L, height - 1, 1);

			add_mod(ret, L1);
		}
		else
		{
			ll L0 = 0, R0 = 0, L1 = 0, R1 = 0;

			if (R >= height - 1)
				R1 = solve(R, height - 1, 1);
			R0 = solve(R, min(height - 1, (ll)R), 0);

			if (L >= height - 1)
				L1 = solve(L, height - 1, 1);
			L0 = solve(L, min(height - 1, (ll)L), 0);

			ll fir = ((R0 % MOD) * (L0 % MOD)) % MOD;

			ll sec = ((R0 % MOD) - (R1 % MOD) + MOD) % MOD;

			ll thi = ((L0 % MOD) - (L1 % MOD) + MOD) % MOD;

			ll fou = ((sec % MOD) * (thi % MOD)) % MOD;

			ll ans = ((fir % MOD) - (fou % MOD) + MOD) % MOD;

			add_mod(ret, ans);

			// (a + b) * (c + d) = ac + ad + bc + bd (곱셈법칙 사용)
		}
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	memset(DP, -1, sizeof(DP));

	cout << solve(N, M, 1);
}