#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, Arr[11]{ 0 }, total, parti;

bool Vis[11]{ 0 };

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve(ll Idx, ll Cnt, ll standard)
{
	if (Cnt == standard)
	{
		ll lcm = 0, Chk = 0;

		for (ll i = 0; i < N; i++)
		{
			if (Vis[i])
			{
				Chk == 0 ? lcm = Arr[i] : lcm = (Arr[i] * lcm) / gcd(Arr[i], lcm);
				Chk++;
			}
		}

		parti += M / lcm;

		return;
	}

	for (ll i = Idx; i < N; i++)
	{
		if (Vis[i])
			continue;
		Vis[i] = true;
		solve(i + 1, Cnt + 1, standard);
		Vis[i] = false;
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 1; i <= N; i++)
	{
		parti = 0;
		solve(0, 0, i);
		i % 2 != 0 ? total += parti : total -= parti;
	}

	cout << total << '\n';
}