#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAX 300000
#define MOD 1000000007

using namespace std;

ll N, Arr[MAX + 1]{ 0 }, Pre_Sum[MAX + 1]{ 0 }, DP[MAX + 1]{ 0 };

void Init()
{
	for (ll i = 1; i <= N; i++)
		Pre_Sum[i] = Pre_Sum[i - 1] + Arr[i - 1];
}

ll dev_con(ll pows)
{
	if (pows == 0)
		return 1;

	ll& ret = DP[pows];

	if (ret != 0)
		return ret;

	if (pows % 2 == 0)
	{
		ll T1 = dev_con(pows / 2);
		return ret = ((T1 % MOD) * (T1 % MOD)) % MOD;
	}

	return ret = ((2 % MOD) * (dev_con(pows - 1) % MOD)) % MOD;
}

ll solve()
{
	ll Ans = 0;

	for (ll i = 1; i < N; i++)
	{
		ll L = Pre_Sum[N] - Pre_Sum[N - i], R = Pre_Sum[i];
		Ans = ((Ans % MOD) + (((L - R) % MOD) * (dev_con(i - 1) % MOD)) % MOD) % MOD;
	}

	return Ans;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	Init();

	cout << solve() << '\n';
}