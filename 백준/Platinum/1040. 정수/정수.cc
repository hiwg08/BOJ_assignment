#include <bits/stdc++.h>
#define ll long long
#define o (ll)1

using namespace std;

ll N, K, zari, total = LLONG_MAX;

ll DP[20][1 << 11][2]{ 0 }; // DP[idx][bit][flag] : 현재까지 idx 번째까지 숫자를 봐왔고, 현재 사용된 수의 상태가 bit이며 (ex. bit가 22면 10110으로, 4, 2, 1이 쓰임), 원래의 수보다 큰 수가 쓰였냐? (flag(Y/N))일 때, K개의 서로 다른 숫자로 만들 수 있냐?(T/F)로 정의

ll mask[20]{ 0 };

ll solve(ll Idx, ll bit, ll flag, ll num) // ****num은 top-down dp 시 영향을 주지 않는 변수이기 때문에 넣어도 무방하다.****
{
	if (Idx >= zari) // 모든 자릿수를 전부 확인했을 때
	{
		if ((ll)__builtin_popcount(bit) == K) // 현재 bit 상태에 1로 불이 켜진 게 정확하게 K개일 때에만 1을 반환한다. 
		{
			total = min(total, num); // 값을 갱신.
			return 1;
		}
		return 0; // 그게 아니라면 전부 0을 반환.
	}

	ll& ret = DP[Idx][bit][flag];

	if (ret != -1)
		return ret; // 124__이나, 421__, 412__, 214__이나 뒤에 두 자리 숫자가 그 어떤 것이 와도 답은 동일하다. 그래서 dp를 사용한 것. 
	                // 그래서 124__가 된다면 421__, 412__ 등등을 볼 필요가 없어지고, 어차피 답은 가장 작은 수인 124__이기 때문에 dp를 이렇게 세워도 논리적 오류가 없다.

	ll start = 0;

	if (!flag)
		start = mask[Idx]; // flag가 false이면 큰 수가 쓰이지 않았으므로 원래의 수에 해당하는 자릿수가 start가 된다.

	for (ll i = start; i <= 9; i++) // start부터 자릿수의 최대치인 9까지 탐색.
	{
		if (!flag)
		{
			if (solve(Idx + 1, bit | (o << i), i != mask[Idx], num * 10 + i) == 1) // 12 -> 13, 14, ...으로 넘어가는 경우는 수가 커지는 시점이므로 flag를 true로 변경. 그게 아니라면 여전히 flag는 false.
				return ret = 1;
		}
		else
		{
			if (solve(Idx + 1, bit | (o << i), 1, num * 10 + i) == 1) // flag가 true이면 다음 상태의 flag도 반드시 1이다. (수가 커졌으므로 뒤에 아무 숫자나 와도 항상 N보다 크기 때문)
				return ret = 1;
		} // 한번이라도 true가 된 flag는 앞으로도 계속 flag라는 사실을 놓쳤다. 주의하자.
	}

	return ret = 0;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	string S = to_string(N);

	ll size_to = (ll)(S.size());

	zari = max(size_to, K); // 자릿수는 원래의 수의 자릿수와 K 중 큰 것을 고른다.

	if (size_to >= K)
	{
		for (ll i = 0; i < (ll)S.length(); i++)
			mask[i] = (ll)(S[i] - '0');
	} // 원래 자릿수가 더 크면 원래 자릿수에 해당하는 수를 mask에 넣는다. (ex. 12345 3)이라면, 12345의 자릿수는 5로 K(= 3)개로 구성이 가능하다. (12311도 있고, 15121도 있고, ...)
	else
	{
		memset(mask, 0, sizeof(mask));

		mask[0] = 1; // 자연수는 항상 1부터 시작하므로 0번째를 1로 설정하자.
	} // 원래 자릿수가 작다면 그 자릿수로는 K개의 서로 다른 숫자로 구성할 수가 없다. 따라서 이 경우는 맨 처음부터 시작해야하므로, 0번째 자리(mask[0] = 1)를 제외하고는 전부 0으로 세팅

	// (ex. 78 3)이라면, 78의 자릿수인 2로는 절대로 K(= 3)을 구성할 수가 없다. 적어도 100 이상이 되야한다는 뜻임. 

	if (solve(0, 0, 0, 0) == 1)
	{
		cout << total;
		exit(0);
	}

	zari++;

	memset(DP, -1, sizeof(DP));

	memset(mask, 0, sizeof(mask));

	mask[0] = 1;

	// 자릿수를 하나 더 늘린 후, 마찬가지로 0번째 자릿수를 1로 세팅, 나머지는 전부 0으로 세팅한 다음 dp를 돌리자.
	// 이 경우는 K개의 서로 다른 숫자로 구성되는 수가 반 드 시 존재한다. (너무 자명한 사실)
	// 그래서 dp는 많아봐야 총 2번만 돌리면 된다.

	if (solve(0, 0, 0, 0) == 1)
		cout << total;
}
