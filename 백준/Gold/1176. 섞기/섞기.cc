#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K, Ans, Arr[17]{ 0 };

ll DP[16][1 << 16]{ 0 };

ll solve(ll Last, ll Bits)
{
	if (Bits == ((ll)1 << N) - 1)
		return 1;

	ll& ret = DP[Last][Bits];

	if (ret != -1)
		return ret;

	ret = 0;

	for (ll i = 0; i < N; i++)
	{
		if (!(Bits & ((ll)1 << i)) && abs(Arr[Last] - Arr[i]) > K)
			ret += solve(i, Bits | ((ll)1 << i));
	}

	return ret;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	for (ll i = 0; i < N; i++)
		Ans += solve(i, (ll)1 << i);

	cout << Ans << '\n';
}