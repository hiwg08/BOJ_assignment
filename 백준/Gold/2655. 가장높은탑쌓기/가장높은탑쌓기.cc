#include <bits/stdc++.h>
#define tiiii tuple<int, int, int, int>

using namespace std;

int N, DP[101]{ 0 }, Trace[101]{ 0 };

vector<tiiii> V;

vector<int> Ans;

bool cmp(tiiii a, tiiii b)
{
	return get<0>(a) > get<0>(b);
}

int solve(int Idx)
{
	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = get<1>(V[Idx]);

	for (int i = Idx + 1; i < N; i++)
	{
		if (get<2>(V[Idx]) > get<2>(V[i]))
		{
			int T = solve(i);

			if (ret < T + get<1>(V[Idx]))
			{
				ret = T + get<1>(V[Idx]);
				Trace[Idx] = i;
			}
		}
	}

	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0, a, b, c; i < N; i++)
	{
		cin >> a >> b >> c;
		V.push_back({ a, b, c, i + 1 });
	}

	sort(V.begin(), V.end(), cmp);

	memset(DP, -1, sizeof(DP));

	memset(Trace, -1, sizeof(Trace));

	for (int i = 0; i < N; i++)
		solve(i);

	int MAX = INT_MIN, Idx = -1;

	for (int i = 0; i < N; i++)
	{
		if (MAX < DP[i])
			MAX = DP[i], Idx = i;
	}

	Ans.push_back(Idx);

	while (Idx >= 0 && Trace[Idx] != -1)
	{
		Ans.push_back(Trace[Idx]);
		Idx = Trace[Idx];
	}

	cout << (int)Ans.size() << '\n';

	for (int i = (int)Ans.size() - 1; i >= 0; i--)
		cout << get<3>(V[Ans[i]]) << '\n';
}