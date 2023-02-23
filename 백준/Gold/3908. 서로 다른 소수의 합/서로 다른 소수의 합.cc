#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1120

using namespace std;

int T, DP[MAX + 1][15]{ 0 };

bool CHK[1121]{ 0 };

vector<int> V;

void primal()
{
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (CHK[i]) 
			continue;
		for (int j = i; j <= MAX; j += i)
		{
			if (i != j)
				CHK[j] = true;
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (!CHK[i]) 
			V.push_back(i);
	}
}

void Init()
{
	DP[0][0] = 1;
	
	for (int i = 0; i < (int)V.size(); i++)
	{
		for (int j = MAX; j >= V[i]; j--)
		{
			for (int k = 14; k >= 1; k--)
				DP[j][k] += DP[j - V[i]][k - 1];
		}
	}
}

int main()
{
	fastio;

	cin >> T;

	primal();

	Init();

	while (T--)
	{
		int a, b; cin >> a >> b;
		cout << DP[a][b] << '\n';
	}
}