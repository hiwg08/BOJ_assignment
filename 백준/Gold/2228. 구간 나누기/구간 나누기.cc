#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, M;

int Arr[101]{ 0 };

pii DP[101][101];

void init()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
			DP[i][j] = { -1, -1 };
	}
}

pii solve(int Idx, int interval)
{
	if (interval == 0) // 여기는 무조건 된 것
		return { 0, 1 };

	if (Idx >= N)
	{
		if (interval > 0)
			return { INT_MAX, 0 };
		return { 0, 1 };
	}

	pii& ret = DP[Idx][interval];

	if (ret.y != -1)
		return ret;

	ret.x = INT_MIN, ret.y = 0;

	int sum = 0;

	for (int i = Idx; i < N; i++)
	{
		sum += Arr[i];

		pii T1 = solve(i + 2, interval - 1);

		if (T1.y == 1) // 이 경우에만 값 갱신 허용.
		{
			ret.y = 1;
			ret.x = max(ret.x, sum + T1.x);
		}
	}

	pii T1 = solve(Idx + 1, interval);

	if (T1.y == 1)
	{
		ret.y = 1;
		ret.x = max(ret.x, T1.x);
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	init();

	cout << solve(0, M).x;
}
