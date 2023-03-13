#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

ll Arr[100001]{ 0 };

ll pre_sum[100001]{ 0 };

ll DP1[100001]{ 0 };

ll DP2[100001]{ 0 };

ll ans[100001]{ 0 };

ll total;

ll output;

int main()
{
	cin >> N;

	for (ll i = 1; i <= N; i++)
	{
		cin >> Arr[i];

		pre_sum[i] = pre_sum[i - 1] + Arr[i];
	}
	
	total = pre_sum[N];

	if (Arr[1] * 4 == total)
		DP1[1]++;

	for (ll i = 2; i <= N - 2; i++)
	{
		ll L = pre_sum[i], R = pre_sum[N] - pre_sum[i];

		if (L == R)
			ans[i] = DP1[i - 1];

		DP1[i] = DP1[i - 1];

		if (L * 4 == total)
			DP1[i]++;
	}

	if (Arr[N] * 4 == total)
		DP2[N]++;

	for (ll i = N - 1; i >= 3; i--)
	{
		ll L = pre_sum[i - 1], R = pre_sum[N] - pre_sum[i - 1];

		if (L == R)
			output += (ans[i - 1] * DP2[i + 1]);

		DP2[i] = DP2[i + 1];

		if (R * 4 == total)
			DP2[i]++;
	}

	cout << output << '\n';	
}