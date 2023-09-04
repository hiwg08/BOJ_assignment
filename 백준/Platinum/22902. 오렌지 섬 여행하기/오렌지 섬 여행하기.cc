#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[1010]{ 0 };

ll reall[1010]{ 0 };

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
				reall[j]++;
				arr[j]++;
			}
		}
	}
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
					if (arr[L] == 0)
						left_first = false;
					else
						left_first = true;

					while (arr[R] == 0 && R >= 0)
						R--;

					L = R - 1;

					while (arr[L] == 0 && L >= 0)
						L--;
					
					break;
				}

				arr[R]--, total--;
				cout << R << " ";
				V.push_back(R);

				if (arr[L] == 0)
				{
					if (arr[R] != 0)
						left_first = true;
					else
						left_first = false;

					while (arr[R] == 0 && R >= 0)
						R--;

					L = R - 1;

					while (arr[L] == 0 && L >= 0)
						L--;

					break;
				}

				arr[L]--, total--;
				cout << L << " ";
				V.push_back(L);
			}
		}
		else
		{
			while (true)
			{
				if (arr[L] == 0)
				{
					if (arr[R] != 0)
						left_first = true;
					else
						left_first = false;

					while (arr[R] == 0 && R >= 0)
						R--;

					L = R - 1;

					while (arr[L] == 0 && L >= 0)
						L--;
					break;
				}

				arr[L]--, total--;
				cout << L << " ";
				V.push_back(L);

				if (arr[R] == 0)
				{
					if (arr[L] == 0)
						left_first = false;
					else
						left_first = true;

					while (arr[R] == 0 && R >= 0)
						R--;

					L = R - 1;

					while (arr[L] == 0 && L >= 0)
						L--;
					break;
				}

				arr[R]--, total--;
				cout << R << " ";
				V.push_back(R);

				reall[R]--;
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