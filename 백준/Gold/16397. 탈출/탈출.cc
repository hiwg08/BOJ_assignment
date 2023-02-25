#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, T, G;

bool Vis[100001]{ 0 };

bool calculate(int& ret, int dir)
{
	if (dir == 0)
	{
		ret += 1;

		if (ret > 99999)
			return false;
	}
	else
	{
		ret *= 2;

		if (ret > 99999)
			return false;

		string S = to_string(ret);

		ret -= (int)pow(10, (int)S.size() - 1);

		if (ret == -1) ret = 0;
	}

	return true;
}

int solve()
{
	queue<pii> Q;

	Q.push({ N, 0 });

	Vis[N] = true;

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		if (T1.x == G)
			return T1.y;

		for (int dir = 0; dir < 2; dir++)
		{
			int cpy = T1.x;

			if (calculate(cpy, dir))
			{
				if (!Vis[cpy])
				{
					Vis[cpy] = true;
					Q.push({ cpy, T1.y + 1 });
				}
			}
		}
	}

	return INT_MAX;
}

int main()
{
	cin >> N >> T >> G;

	int ans = solve();

	ans <= T ? cout << ans << '\n' : cout << "ANG" << '\n';
}