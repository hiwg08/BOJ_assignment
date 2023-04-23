#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll DP[31]{ 0 };

ll stand = (ll)pow(10, 9);

ll T, A, B;

void init()
{
	DP[0] = 0, DP[1] = 2; // DP[2] = 4, DP[3] = 7, ....

	for (ll i = 2; i <= 30; i++)
		DP[i] = DP[i - 1] + i;
}

ll solve(ll start, ll end, ll cmd_a, ll cmd_b, ll nu_sum, ll posi) // posi가 기준이 된다.
{
	ll ret = LLONG_MIN;

	for (ll i = 0; i <= 30; i++)
	{
		ll pre = (o << i) - 1 + posi, nxt = (o << (i + 1)) - 2 + posi;

		if (pre >= end) // 종료 조건
		{
			if (pre == end && (cmd_a <= pre && pre <= cmd_b))
				ret = max(ret, nu_sum + i);

			break;
		}

		if (cmd_a > nxt || cmd_b < pre)
			continue;

		if (cmd_a <= pre && nxt <= cmd_b) // 해당 구간은 완전히 포함하는 경우
		{
			ret = max(ret, DP[i] + nu_sum);
			continue;
		}

		if (cmd_b <= nxt)
		{
			ret = max(ret, solve(pre, nxt, max(cmd_a, pre), min(cmd_b, nxt), nu_sum + i, pre));
			continue;
		}	

		if (cmd_a >= pre)
			ret = max(ret, solve(pre, nxt, max(cmd_a, pre), min(cmd_b, nxt), nu_sum + i, pre));
	}

	return ret;
}

int main()
{
	init();

	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		cout << solve(0, stand, A, B, 0, 0) << '\n';
	}
}