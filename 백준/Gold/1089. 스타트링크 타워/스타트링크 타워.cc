#include <bits/stdc++.h>
#define int long long
#define vvi vector<vector<long long>>
using namespace std;

int N, quo;

double Ans;

char Map[51][51]{ 0 };

vector<vvi> Ele{ {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}, { {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1} },
{ {1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1} }, { {1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} },
{ {1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1} }, { {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} },
{ {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1} }, {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1} },
{ {1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1} }, { {1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1} } };

int Cnt[10]{ 0 };

void Input()
{
	cin >> N;

	for (int i = 0; i < 5; i++)
	{
		string S; cin >> S;

		for (int j = 0; j < 4 * (N - 1) + 3; j++)
			Map[i][j] = S[j];
	}
}

int32_t main()
{
	Input();

	for (int i = 0; i < N; i++)
	{
		memset(Cnt, 0, sizeof(Cnt));

		int total = 0;

		for (int k = 0; k < 5; k++)
		{
			for (int q = 0; q < 3; q++)
			{
				if (Map[k][4 * i + q] == '#')
					total++;
			}
		}

		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				for (int q = 0; q < 3; q++)
				{
					if (Ele[j][k][q] == 1 && Map[k][4 * i + q] == '#')
						Cnt[j]++;
				}
			}
		}

		int par_sum = 0, cn = 0;

		bool CHK = false;

		for (int q = 0; q < 10; q++)
		{
			if (Cnt[q] == total)
			{
				par_sum += (int)pow(10, N - i - 1) * q;
				cn++;
				CHK = true;
			}
		}

		if (!CHK)
		{
			cout << -1 << '\n';
			exit(0);
		}

		Ans += (double)par_sum / cn;
	}

	cout.precision(5);

	cout << fixed << Ans << '\n';
}