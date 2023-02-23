#include <bits/stdc++.h>

using namespace std;

int N, M, Arr[11]{ 0 }, DP[51]{ 0 };

int Trace[51]{ 0 };

string Ans = "";

vector<string> V;

bool cmp(string a, string b)
{
	if ((int)a.length() == (int)b.length())
		return a > b;
	return (int)a.length() > (int)b.length();
}

void Init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	cin >> M;

	int Idx = M, Cnt = 0;

	while (Idx >= 0)
	{
		memset(DP, 0, sizeof(DP));
		memset(Trace, 0, sizeof(Trace));

		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j <= Idx; j++)
			{
				if (j - Arr[i] >= 0)
				{
					if (DP[j - Arr[i]] + 1 >= DP[j])
					{
						DP[j] = DP[j - Arr[i]] + 1;
						Trace[j] = i;
					}
				}
			}
		}

		string S = "";

		int T = Idx;

		while (T != 0 && DP[T] != 0)
		{
			S += to_string(Trace[T]);
			T -= Arr[Trace[T]];
		}

		for (int i = 0; i < Cnt; i++)
			S += '0';

		bool CHK = false;

		for (int i = 0; i < (int)S.length(); i++)
		{
			if (S[i] != '0')
				CHK = true;
		}

		CHK ? V.push_back(S) : V.push_back("0");

		Idx -= Arr[0], Cnt++;
	}
}

int main()
{
	Init();

	sort(V.begin(), V.end(), cmp);

	cout << V[0] << '\n';
}