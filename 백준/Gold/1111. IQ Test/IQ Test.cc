#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;

ll arr[51]{ 0 };

int main()
{
	cin >> n;

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 1)
	{
		cout << 'A';
	}
	else if (n == 2)
	{
		if (arr[0] != arr[1])
			cout << 'A';
		else
			cout << arr[0];
	}
	else
	{
		if (arr[0] == arr[1])
		{
			for (ll i = 2; i < n; i++)
			{
				if (arr[i] != arr[0])
				{
					cout << 'B';
					exit(0);
				}
			}
			cout << arr[0];
		}
		else
		{
			if ((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0)
			{
				cout << 'B';
			}
			else
			{
				ll a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
				ll b = arr[1] - (a * arr[0]); // (same as arr[2] - (a * arr[1])

				ll flag = 1;

				for (ll i = 3; i < n && flag == 1; i++)
				{
					if (arr[i - 1] * a + b != arr[i])
						flag = -1;
				}

				if (flag == -1)
					cout << 'B';
				else
					cout << arr[n - 1] * a + b;
			}
		}
	}
}