#include <bits/stdc++.h>

using namespace std;

int N, K, Arr[101]{ 0 };

bool Vis[101]{ 0 };

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int Cnt = 0, Idx = 0;
	
	Vis[0] = true;

	while (true)
	{	
		int Pre = Arr[Idx], temp_Idx = INT_MAX;

		for (int i = Idx + 1; i < N; i++)
		{
			if (Vis[i])
				continue;
			if (Pre > Arr[i])
				temp_Idx = min(temp_Idx, i);
			else
			{
				Pre = Arr[i];
				Vis[i] = true;
			}
		}

		Cnt++;
		if (temp_Idx == INT_MAX) break;
		Idx = temp_Idx;
	}

	Cnt <= K ? cout << "YES" << '\n' : cout << "NO" << '\n';
}