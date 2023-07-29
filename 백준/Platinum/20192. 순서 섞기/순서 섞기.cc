#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, total, ans;

ll Arr[300001]{ 0 };

void solve()
{
	if (N == 1)
		return;

	bool inc = true;

	for (ll i = 1; i < N; i++)
	{
		if (Arr[i - 1] > Arr[i])
		{
			if (inc)
			{
				total++;
				inc = false;
			}
		}
		else if (Arr[i - 1] < Arr[i])
		{
			if (!inc)
				inc = true;
		}
	}

	if (total >= 1 && inc)
		total++;

	while (total != 0)
	{
		ll pre = total;

		total /= 2;

		if ((pre % 2 != 0) && (pre != 1))
			total++;

		ans++;
	}
}

int main()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	solve();

	cout << ans;
}