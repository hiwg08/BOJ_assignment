#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

ll N, M;

ll ans[500001]{ 0 };

void recomplish(ll R1, ll R2, string S)
{
	ll T1 = R1, T2 = R2;

	for (ll i = (ll)S.length() - 1; i >= 0; i--)
	{
		T1 <<= 1, T2 <<= 1;

		if (S[i] == '1')
			T1 |= 1, T2 |= 1;
	}

	ans[T1] = T2;
}

void solve(ll L1, ll R1, ll L2, ll R2, string S)
{
	ll sz = R1 - L1 + 1;

	if (sz == 1)
	{
		recomplish(R1, R2, S);
		return;
	}

	if ((sz & o) == 1) // 홀수일 때
	{
		if ((L2 & o) == 1)
		{
			recomplish(R1, R2, S);

			solve(L1 >> 1, (R1 - 1) >> 1, L2 >> 1, (R2 - 2) >> 1, S + '1');
			solve(L1 >> 1, (R1 - 1) >> 1, (L2 + 1) >> 1, (R2 - 1) >> 1, S + '0');
			return;
		}

		solve(L1 >> 1, R1 >> 1, L2 >> 1, R2 >> 1, S + '0');
		solve(L1 >> 1, (R1 - 1) >> 1, L2 >> 1, (R2 - 1) >> 1, S + '1');
		return;
	}

	if ((L2 & o) == 0)
	{
		solve(L1 >> 1, R1 >> 1, L2 >> 1, R2 >> 1, S + '0');
		solve(L1 >> 1, R1 >> 1, L2 >> 1, R2 >> 1, S + '1');
		return;
	}

	solve(L1 >> 1, R1 >> 1, L2 >> 1, (R2 - 1) >> 1, S + '1');
	solve(L1 >> 1, R1 >> 1, (L2 + 1) >> 1, R2 >> 1, S + '0');
}

int main()
{
	fastio;

	cin >> N >> M;

	solve(0, N - 1, M, M + N - 1, "");

	for (ll i = 0; i <= N - 1; i++)
		cout << i << " " << ans[i] << '\n';
}