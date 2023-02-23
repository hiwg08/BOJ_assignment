#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long

using namespace std;

int S, N, K, R1, R2, C1, C2;

int first, last;

void solve(int x, int y, int params)
{
	if (params == 0)
	{
		cout << '0';
		return;
	}

	int xp = x / params, yp = y / params;

	if ((xp >= first && xp <= last) && (yp >= first && yp <= last)) // 베이스 (별을 찍는 곳)
		cout << '1';
	else
		solve(x % params, y % params, params / N);
}

int32_t main()
{	
	fastio;

	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;

	first = (N - K) / 2, last = N - 1 - first;

	int pows = (int)pow(N, S - 1);

	for (int i = R1; i <= R2; i++)
	{
		for (int j = C1; j <= C2; j++)
			solve(i, j, pows);
		cout << '\n';
	}
}