#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 50

using namespace std;

ll K, N, Fac_L[MAX + 2]{ 0 }, Fac_R[MAX + 2]{ 0 };

void Init()
{
	Fac_L[0] = 1, Fac_R[0] = 1;

	for (ll i = 1; i <= K + 1; i++)
		Fac_L[i] = ((Fac_L[i - 1] % MOD) * (i % MOD)) % MOD;

	for (ll i = N; i <= K + N; i++)
		Fac_R[i - N + 1] = ((Fac_R[i - N] % MOD) * (i % MOD)) % MOD;
}

ll dev_con(ll params, ll pows)
{
	if (pows == 0)
		return 1;

	if (pows % 2 == 0)
	{
		ll T1 = dev_con(params, pows / 2);
		return ((T1 % MOD) * (T1 % MOD)) % MOD;
	}

	return ((params % MOD) * (dev_con(params, pows - 1) % MOD)) % MOD;
}

int main()
{
	cin >> K >> N;

	Init();

	ll Parent = dev_con(Fac_L[K + 1], MOD - 2);

	cout << ((Fac_R[K + 1] % MOD) * (Parent % MOD)) % MOD << '\n';
}