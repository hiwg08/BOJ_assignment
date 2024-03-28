#include <bits/stdc++.h>

using namespace std;

string S;

int N, E, ans, cnt;

int main()
{
	cin >> N >> E;

	cin >> S;

	for (int i = 0; i < (int)S.length(); i++)
	{
		if (S[i] == 'O')
			continue;
		else
		{
			while (S[i + 1] == 'O' && S[i + 2] == 'I')
			{
				cnt++;
				if (cnt == N)
				{
					cnt--;
					ans++;
				}
				i += 2;
			}
			cnt = 0;
		}
	}

	cout << ans;
}