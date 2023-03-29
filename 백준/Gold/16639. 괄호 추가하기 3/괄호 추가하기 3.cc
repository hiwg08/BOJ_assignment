#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N;

string S;

pii DP[20][20];

void init()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			DP[i][j] = { INT_MIN, INT_MAX };
	}
}

pii sol(int L, int R)
{
	if (L == R)
		return { (int)(S[L] - '0'), (int)(S[L] - '0') };

	pii& ret = DP[L][R];

	if (!(ret.x == INT_MIN && ret.y == INT_MAX))
		return ret;

	ret.x = INT_MAX, ret.y = INT_MIN; // x에는 최소, y에는 최대

	for (int i = L; i <= R - 2; i += 2)
	{
		pii T1 = sol(L, i), T2 = sol(i + 2, R);

		int S1 = 0, S2 = 0, S3 = 0, S4 = 0;

		if (S[i + 1] == '+')
		{
			S1 = T1.x + T2.x;
			S2 = T1.x + T2.y;
			S3 = T1.y + T2.x;
			S4 = T1.y + T2.y;
		}
		if (S[i + 1] == '-')
		{
			S1 = T1.x - T2.x;
			S2 = T1.x - T2.y;
			S3 = T1.y - T2.x;
			S4 = T1.y - T2.y;
		}
		if (S[i + 1] == '*')
		{
			S1 = T1.x * T2.x;
			S2 = T1.x * T2.y;
			S3 = T1.y * T2.x;
			S4 = T1.y * T2.y;
		}

		ret.x = min(ret.x, min({ S1, S2, S3, S4 }));
		ret.y = max(ret.y, max({ S1, S2, S3, S4 }));
	}

	return ret;
}

int main()
{
	cin >> N;

	cin >> S;

	init();

	cout << sol(0, N - 1).y;
}

// dp[L][R] : L ~ R 만큼의 구간 상태일 때, 나올 수 있는 최솟값(first), 최댓값(second)
// time complexity : O(N^3)