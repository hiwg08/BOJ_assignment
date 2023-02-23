#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

string S, Arr[51], sort_Arr[51];

int N;

int DP[51]{ 0 };

int calc_cost(string standard, string params)
{
	int Ans = 0;

	for (int i = 0; i < (int)params.length(); i++)
	{
		if (standard[i] != params[i])
			Ans++;
	}

	return Ans;
}

int solve(int Idx)
{
	if (Idx >= (int)S.length())
		return 0;

	int& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = INT_MAX;

	string T = "";

	for (int i = Idx; i < (int)S.length(); i++)
	{
		T += S[i];

		string TT = T;

		sort(all(TT));

		for (int j = 0; j < N; j++)
		{
			if (TT == sort_Arr[j])
			{
				int nxt = solve(i + 1);
				
				if (nxt != INT_MAX)
					ret = min(ret, nxt + calc_cost(T, Arr[j]));
			}
		}
	}

	return ret;
}


int main()
{
	cin >> S;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		sort_Arr[i] = Arr[i];
		sort(all(sort_Arr[i]));
	}

	memset(DP, -1, sizeof(DP));

	solve(0) == INT_MAX ? cout << -1 << '\n' : cout << DP[0] << '\n';
}