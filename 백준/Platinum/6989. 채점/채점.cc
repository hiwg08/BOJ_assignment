#include <bits/stdc++.h>

using namespace std;

bitset<2000000> ms[153];

int N, K, total;

int Arr[153]{ 0 };

int nu = 0;

void solve()
{
	for (int i = 2; i <= N + 1; i++)
	{
		nu = 0;

		for (int j = i; j >= 2; j--)
		{
			nu = Arr[j] + nu + (Arr[j] * (i - j));
			
			total = nu;

			ms[i] |= (ms[j - 2] << nu);

			ms[i].set(nu, true);
		}
		
		ms[i] |= ms[i - 1];
	}
}

void input()
{
	cin >> N;

	for (int i = 2; i <= N + 1; i++)
		cin >> Arr[i];

	cin >> K;
}

int main()
{
	input();

	solve();

	for (int i = K; i <= total; i++)
	{
		if (!ms[N + 1].test(i))
		{
			cout << i;
			exit(0);
		}

		if (i == total)
		{
			cout << K + 1;
			exit(0);
		}
	}

	cout << K;
}