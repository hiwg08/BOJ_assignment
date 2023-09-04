#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[1010]{ 0 };

ll total;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll N;

vector<ll> V;

void precomp()
{
	for (ll i = 1; i < N; i++)
	{
		for (ll j = i + 1; j <= N; j++)
		{
			if (gcd(i, j) == 1)
			{
				total++;
				arr[j]++;
			}
		}
	}
}

void narrow_range(ll& L, ll& R)
{
	while (arr[R] == 0 && R >= 0) R--;

	L = R - 1;

	while (arr[L] == 0 && L >= 0) L--;
}

void solve()
{
	ll L = N - 1, R = N;

	bool left_first = false;

	while (total > 0)
	{
		if (!left_first)
		{
			while (true)
			{
				if (arr[R] == 0)
				{
					arr[L] == 0 ? left_first = false : left_first = true;

					narrow_range(L, R);
					
					break;
				}

				arr[R]--, total--;
				cout << R << " ";

				if (arr[L] == 0)
				{
					arr[R] != 0 ? left_first = true : left_first = false;

					narrow_range(L, R);

					break;
				}

				arr[L]--, total--;
				cout << L << " ";
			}
		}
		else
		{
			while (true)
			{
				if (arr[L] == 0)
				{
					arr[R] != 0 ? left_first = true : left_first = false;

					narrow_range(L, R);

					break;
				}

				arr[L]--, total--;
				cout << L << " ";

				if (arr[R] == 0)
				{
					arr[L] == 0 ? left_first = false : left_first = true;

					narrow_range(L, R);

					break;
				}

				arr[R]--, total--;
				cout << R << " ";
			}
		}
	}
}

int main()
{
	cin >> N;

	precomp();

	arr[1] = 1, total++;

	solve();
}