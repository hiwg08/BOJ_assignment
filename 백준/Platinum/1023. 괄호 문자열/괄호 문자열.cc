#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;

ll DP[51][51][51][2]{ 0 }; // dp[L][R][round][state] : 현재까지 사용한 '('의 개수가 L, ')'의 개수가 R, 왼쪽 괄호를 오른쪽 괄호로 상쇄(?) 시켜주는 횟수가 round, '괄호 문자열인 상태에서' 오른쪽 괄호가 쓰였냐 (state)로 이루어질 때, 만들 수 있는 괄호 ㄴㄴ 문자열의 개수로 정의.

ll solve(ll L, ll R, ll round, ll state)
{
	if (L + R == N)
	{
		if (round != 0 || state == 1) // round가 0이 아니라는 뜻은 오른쪽 괄호로 전부 상쇄하지 못했다는 뜻. state가 1임은 맨 처음부터 오른쪽 괄호가 쓰였다는 뜻. 이 때만 괄호 ㄴㄴ 문자열이므로 1 리턴
			return 1;
		return 0; // 그게 아니라면 괄호 ㅇㅇ 문자열이므로 0 리턴 
	}

	ll& ret = DP[L][R][round][state];

	if (ret != -1)
		return ret;

	// 1. 오른쪽 괄호를 넣는 경우

	ret = 0;

	if (state == 1) // 맨 처음부터 오른쪽 괄호가 쓰인거면 무조건 괄호 ㄴㄴ 문자열이다. 그래서 round 값 상관 없이 왼, 오른쪽 괄호 진짜 아무거나 다 넣어도 된다.
	{
		ret += solve(L + 1, R, round, state);
		ret += solve(L, R + 1, round, state);
	}
	
	else // 그게 아닐 시
	{
		if (round >= 1) // 아직 오른쪽 괄호로 상쇄할 왼쪽 괄호가 남아있을 때 --> 사실 여기는 현재로서 괄호 문자열인지, 아닌지 확인 못 한다. 그래서 다 해봐야 함.
		{
			ret += solve(L + 1, R, round + 1, state);
			ret += solve(L, R + 1, round - 1, state);
		}
		else  // 아직 오른쪽 괄호로 상쇄할 왼쪽 괄호가 남아있지 않을 때 --> 여기는 괄호 ㅇㅇ 문자열인 상태. L을 넣어주면 round를 1 증가시켜주고, R을 넣어주면 state를 1로 켜주자.
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

	if (state == 1)
	{
		ll Q = solve(L + 1, R, round, state);

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
} // dp 함수 고~~대로 답 재구성 (쉽죠잉)

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	if (solve(0, 0, 0, 0) <= K) // K가 0부터 시작이므로 조건을 이렇게 걸어줘야 한다.
	{
		cout << -1;
		return 0;
	}

	reconstruct(0, 0, 0, 0, K + 1); // 그러나 시작은 K에 1을 더해서 시작해주자. 배열과는 다르게, 괄호 ㄴㄴ 문자열의 '개수'이기 때문에 0부터 시작하면 상당히 헷갈린다.
}
