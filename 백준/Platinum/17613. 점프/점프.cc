#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll stand = (ll)pow(10, 9);

ll T, A, B;

ll solve(ll start, ll end, ll cmd_a, ll cmd_b, ll nu_sum, ll posi) // 마치 세그 트리 같은 매개 변수 선언이다 ㅋㅋㅋ start ~ end 구간이 있을 때, cmd_a ~ cmd_b에서 보는 점프 넘버의 최댓값. 시작 위치는 항상 posi가 기준이 된다.
{
	ll ret = LLONG_MIN; // 최대라서 0으로 했으면 더 좋았을 듯... 뭐 어차피 쿼리는 x <= y고, 모든 구간은 적어도 한 개는 점프해야 하니까 상관은 없지만.

	ll maxi_cur = 0;

	for (ll i = 0; i <= 30; i++) // 10^9는 2^30보다 작다. 그래서 이렇게 한 거다. 0부터 시작해야 차질이 없다. 규칙 때문이다.
	{
		if (i >= 1)
		{
			if (i == 1)
				maxi_cur = 1;
			maxi_cur += i;
		}

		ll pre = (o << i) - 1 + posi, nxt = (o << (i + 1)) - 2 + posi; // ***posi를 더해야 말이 됨.*** 마치 4256 (트리) 생각하면 된다.

		if (pre >= end) // 종료 조건
		{
			if (pre == end && (cmd_a <= pre && pre <= cmd_b))
				ret = max(ret, nu_sum + i);

			break;
		}

		if (cmd_a > nxt || cmd_b < pre) // 구간 벗어나는 경우 스킵.
			continue;

		if (cmd_a <= pre && nxt <= cmd_b) // 해당 구간은 완전히 포함하는 경우
		{
			ret = max(ret, maxi_cur + nu_sum);
			continue;
		}

		if (cmd_b <= nxt)
		{
			ret = max(ret, solve(pre, nxt, max(cmd_a, pre), min(cmd_b, nxt), nu_sum + i, pre)); // ***이미 pre에서 posi를 더해주고 있다.*** 그래서 pre + posi 이렇게 안 해도 되고, 다음 위치는 pre 그 자체이다. ㅇㅇ
			continue;
		}	

		if (cmd_a >= pre)
			ret = max(ret, solve(pre, nxt, max(cmd_a, pre), min(cmd_b, nxt), nu_sum + i, pre)); // 시작 구간은 max(cmd_a, pre), 종료 구간은 min(cmd_b, nxt)
		// 위의 if문 2개는 한 쪽만 걸치는 경우.
		// 구간 별 처리 방법은 따로 정리 해놓는 편이 좋겠다.
	}

	return ret;
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		cout << solve(0, stand, A, B, 0, 0) << '\n';
	}
}
