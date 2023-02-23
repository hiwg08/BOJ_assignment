#include <bits/stdc++.h>
#define ll long long
#define MAX (ll)1e16

using namespace std;

ll A, B, DP[64]{ 0 };

void Init()
{
	DP[1] = 1;

	for (ll i = 2;; i++)
	{
		if (((ll)1 << (i - 1)) > MAX)
			break;
		DP[i] = ((ll)1 << (i - 1)) + 2 * DP[i - 1];
	}
}

ll solve(ll params)
{
	if (params == 0)
		return 0;

	ll i = 0;

	for (i = 63; i >= 0; i--)
	{
		if (params & ((ll)1 << i))
			break;
	}

	ll upper_one = params - ((ll)1 << i) + 1;
	ll nxt = DP[(ll)log2(((ll)1 << i))];
	ll r_nxt = solve(params - ((ll)1 << i));

	return upper_one + nxt + r_nxt;
}

int main()
{
	Init();

	cin >> A >> B;

	cout << solve(B) - solve(A - 1) << '\n';
}