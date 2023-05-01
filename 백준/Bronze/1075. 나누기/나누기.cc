#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, F;

ll conv_N;

int main()
{
	cin >> N >> F;

	conv_N = (N / 100); conv_N *= 100;

	for (ll i = 0; i <= 99; i++)
	{
		ll comp = conv_N + i;

		if (!(comp % F))
		{
			i <= 9 ? cout << 0 << i : cout << i;
			exit(0);
		}
	}
}