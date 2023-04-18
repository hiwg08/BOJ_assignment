#include <bits/stdc++.h>

using namespace std;

multiset<int> ms[101];

int N, M, total;

void solve(int Idx, int standard)
{
	for (int i = Idx; i >= 1; i--)
	{
		while (!ms[i].empty())
		{
			auto it = ms[i].lower_bound(standard);

			if (it == ms[i].end())
				break;

			standard = *it;

			ms[i].erase(it);
		}
	}
}

void input()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1, a; j <= M; j++)
		{
			cin >> a;
			if (a == 1)
				ms[i].insert(-j);
		}
	}
}

int main()
{
	input();

	for (int i = N; i >= 1; i--)
	{
		if (!ms[i].empty())
		{
			total++;

			int T = *(ms[i].begin());

			auto it = ms[i].lower_bound(T);

			ms[i].erase(it);

			solve(i, T);
		}	
	}

	cout << total;
}