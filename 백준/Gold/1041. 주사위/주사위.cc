#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll N, total;

ll d[6]{ 0 };

ll a[2]{ 0, 5 }, b[2]{ 1, 4 }, c[2]{ 2, 3 };

ll get_third()
{
	ll min_val = LLONG_MAX;

	for (ll i = 0; i < 2; i++)
	{
		for (ll j = 0; j < 2; j++)
		{
			for (ll k = 0; k < 2; k++)
				min_val = min(min_val, d[a[i]] + d[b[j]] + d[c[k]]);
		}
	}

	return min_val;
}

ll get_second()
{
	ll min_val = LLONG_MAX;

	for (ll i = 0; i < 2; i++)
	{
		for (ll j = 1; j <= 4; j++)
			min_val = min(min_val, d[a[i]] + d[j]);
	}

	for (ll j = 0; j < 2; j++)
	{
		for (ll k = 0; k < 2; k++)
			min_val = min(min_val, d[b[j]] + d[c[k]]);
	}

	return min_val;
}

int main()
{
	cin >> N;
	
	for (ll i = 0; i < 6; i++)
		cin >> d[i];

	if (N == 1)
	{
		sort(d, d + 6);

		for (ll i = 0; i < 5; i++)
			total += d[i];

		cout << total;
		exit(0);
	}

	ll fir = 4 * (N - 1) * (N - 2) + (N - 2) * (N - 2);
	ll sec = 4 * (N - 2) + 4 * (N - 1);

	cout << (*min_element(d, d + 6) * fir) + (get_second() * sec) + (get_third() * 4);
}