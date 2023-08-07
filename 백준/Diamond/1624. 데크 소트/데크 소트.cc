#include <bits/stdc++.h>

using namespace std;

int N, total;

int Arr[1001]{ 0 }, tmp[1001]{ 0 };

bool vis[1001]{ 0 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		tmp[i] = Arr[i];
	}

	sort(tmp, tmp + N);

	int n = 0;

	while (n < N)
	{
		total++;

		int Idx = 0;

		for (int i = N - 1; i >= 0; i--)
		{
			if (n >= N)
				break;
			if (!vis[i] && Arr[i] == tmp[n])
			{
				vis[i] = true;
				Idx = i;
				n++;
			}
		}

		for (int i = Idx; i < N; i++)
		{
			if (n >= N)
				break;
			if (!vis[i] && Arr[i] == tmp[n])
			{
				vis[i] = true;
				n++;
			}
		}
	}

	cout << total;
}