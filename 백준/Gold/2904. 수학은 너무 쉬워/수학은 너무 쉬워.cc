#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX (int)(1e6)

using namespace std;

int N, gcd_ans = 1, cnt_ans = 0;

int Arr[101]{ 0 };

bool Vis[MAX + 1]{ 0 };

int Count[MAX + 1]{ 0 };

vector<int> R[MAX + 1];

void Init()
{
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (Vis[i])
			continue;

		for (int j = i; j <= MAX; j += i)
		{
			if (i != j)
				Vis[j] = true;
		}
	}
}

void solve1(int params)
{
	int Idx = 2;

	while (params != 1 && Idx <= MAX)
	{
		if (Vis[Idx])
		{
			Idx++;
			continue;
		}

		int Cnt = 0;

		while (params % Idx == 0)
		{
			params /= Idx;
			Cnt++;
		}

		Count[Idx] += Cnt;

		R[Idx].push_back(Cnt);

		Idx++;
	}
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	Init();

	for (int i = 0; i < N; i++)
		solve1(Arr[i]);

	for (int i = 2; i <= MAX; i++)
	{
		if ((int)R[i].size() != 0)
		{
			while ((int)R[i].size() < N)
				R[i].push_back(0);

			sort(R[i].begin(), R[i].end());

			for (auto e : R[i])
			{
				if (e >= Count[i] / N)
					break;
				cnt_ans += ((Count[i] / N) - e);
			}

			if (Count[i] / N != 0)
				gcd_ans *= (int)pow(i, (Count[i] / N));
		}
	}

	cout << gcd_ans << " " << cnt_ans << '\n';
}