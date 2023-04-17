#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;

ll DP[51][51][51][2]{ 0 };

ll solve(ll L, ll R, ll round, ll state)
{
	if (L + R == N)
	{
		if (round != 0 || state == 1)
			return 1;
		return 0;
	}

	ll& ret = DP[L][R][round][state];

	if (ret != -1)
		return ret;

	// 1. 오른쪽 괄호를 넣는 경우

	ret = 0;

	if (state == 1) // 여긴 진짜 아무거나 다 넣어도 된다.
	{
		ret += solve(L + 1, R, round, state);
		ret += solve(L, R + 1, round, state);
	}
	
	else
	{
		if (round >= 1)
		{
			ret += solve(L + 1, R, round + 1, state);
			ret += solve(L, R + 1, round - 1, state);
		}
		else
		{
			ret += solve(L + 1, R, round + 1, state);
			ret += solve(L, R + 1, round, 1);
		}
	}

	return ret;
}

void reconstruct(ll L, ll R, ll round, ll state, ll kth)
{
	if (L + R == N)
		return;

	if (state == 1) // 여긴 진짜 아무거나 다 넣어도 된다.
	{
		ll Q = solve(L + 1, R, round, state);
		ll W = solve(L, R + 1, round, state);

		if (kth <= Q)
		{
			cout << "(";
			reconstruct(L + 1, R, round, state, kth);
		}
		else
		{
			cout << ")";
			reconstruct(L, R + 1, round, state, kth - Q);
		}
		return;
	}

	else
	{
		if (round >= 1)
		{
			ll Q = solve(L + 1, R, round + 1, state);
			ll W = solve(L, R + 1, round - 1, state);

			if (kth <= Q)
			{
				cout << "(";
				reconstruct(L + 1, R, round + 1, state, kth);
			}
			else
			{
				cout << ")";
				reconstruct(L, R + 1, round - 1, state, kth - Q);
			}
			return;
		}
		else
		{
			ll Q = solve(L + 1, R, round + 1, state);
			ll W = solve(L, R + 1, round, 1);

			if (kth <= Q)
			{
				cout << "(";
				reconstruct(L + 1, R, round + 1, state, kth);
			}
			else
			{
				cout << ")";
				reconstruct(L, R + 1, round, 1, kth - Q);
			}
			return;
		}
	}
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	if (solve(0, 0, 0, 0) <= K)
	{
		cout << -1;
		return 0;
	}

	reconstruct(0, 0, 0, 0, K + 1);
}