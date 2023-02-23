#include <bits/stdc++.h>
#define MAX (int)1e6
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, L, R;

bool Vis[MAX + 1]{ 0 };

vector<int> V;

void Init()
{
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (Vis[i])
			continue;

		for (int j = i; j <= MAX; j += i)
		{
			if (j != i)
				Vis[j] = true;
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (!Vis[i])
			V.push_back(i);
	}
}

pii solve(int params) // 투 포인터
{
	int lo = 0, hi = (int)(lower_bound(V.begin(), V.end(), params) - V.begin());
	
	int Sum = V[lo] + V[hi];

	while (lo <= hi)
	{
		if (Sum > params)
		{
			hi--;
			if (hi >= 0) Sum = V[lo] + V[hi];
		}
		else if (Sum < params)
		{
			lo++;
			if (lo < (int)V.size()) Sum = V[lo] + V[hi];
		}
		else
			return { V[lo], V[hi] };
	}

	return { -1, -1 };
}

int main()
{
	cin >> N;
	
	Init();
	
	if (N % 2 == 0) L = N / 2, R = N / 2;
	else L = N / 2, R = N / 2 + 1;

	while (L > 0)
	{
		pii A = solve(L), B = solve(R);

		if (A.x != -1 && B.x != -1)
		{
			vector<int> Ans = {A.x, A.y, B.x, B.y};

			sort(Ans.begin(), Ans.end());
			
			for (auto e : Ans)
				cout << e << " ";
			cout << '\n';

			exit(0);
		}

		L--, R++;
	}

	cout << -1 << '\n';
}