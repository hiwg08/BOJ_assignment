#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, Ans, Arr[1000000]{ 0 };

ll popc[20]{ 0 };

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		cin >> Arr[i];

		for (ll j = 19; j >= 0; j--)
		{
			if (Arr[i] & ((ll)1 << j))
				popc[j]++;
		}
	}

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 19; j >= 0; j--)
		{
			if (Arr[i] & ((ll)1 << j))
			{
				popc[j]--;
				Ans += (N - i - 1 - popc[j]) * ((ll)1 << j);
			}
			else
				Ans += popc[j] * ((ll)1 << j);
		}
	}

	cout << Ans << '\n';
}