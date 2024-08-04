#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MAX;

string S;

void solve(char outer, char inner)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (S[i] == outer)
		{
			int cnt = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (S[j] == inner)
					cnt++;
			}

			ans = min(ans, cnt);
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (S[i] == inner)
		{
			int cnt = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (S[j] == outer)
					cnt++;
			}
			ans = min(ans, cnt);
			break;
		}
	}
}

int main()
{
	cin >> n;
	cin >> S;
	
	solve('R', 'B');
	solve('B', 'R');
	// RRRRBBBB 꼴

	cout << ans;
}