#include <bits/stdc++.h>

using namespace std;

int N, Ans, Arr[51]{ 0 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	while (true)
	{
		int Cnt = 0;
		bool Odd_Vis = false;

		for (int i = 0; i < N; i++)
		{
			if (Arr[i] == 0)
			{
				Cnt++;
				continue;
			}
			if (Arr[i] % 2 != 0)
			{
				Odd_Vis = true;
				Arr[i]--;
				Ans++;
			}
		}

		if (Cnt == N) break;

		if (Odd_Vis) continue;

		for (int i = 0; i < N; i++)
			Arr[i] /= 2;

		Ans++;
	}

	cout << Ans << '\n';
}