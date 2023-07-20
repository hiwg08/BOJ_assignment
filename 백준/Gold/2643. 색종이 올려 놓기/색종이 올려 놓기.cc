#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, ans = INT_MIN;

int DP[1001]{ 0 };

vector<pii> V;

int solve(int Idx)
{
	if (Idx == N - 1)
		return 1;

	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = Idx + 1; i < N; i++)
	{
		if (V[Idx].y >= V[i].y)
			ret = max(ret, solve(i) + 1);
	}

	return ret;
}

int main()
{
	cin >> N; V.resize(N);

	for (auto& iv : V)
	{
		cin >> iv.x >> iv.y;
		if (iv.x < iv.y)
			swap(iv.x, iv.y);
	}

	sort(V.begin(), V.end(), [&](pii a, pii b)
	{
		if (a.x == b.x)
			return a.y > b.y;
		return a.x > b.x;
	});

	for (int i = 0; i < N; i++)
	{
		memset(DP, -1, sizeof(DP));
		ans = max(ans, solve(i));
	}

	cout << ans;
}