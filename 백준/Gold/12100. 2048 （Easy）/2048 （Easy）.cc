#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, total = INT_MIN;

vector<vector<ll>> Arr;

void up(vector<vector<ll>>& Arr)
{
	for (ll i = 0; i < N; i++)
	{
		ll j = 0, fir = -1, x = -1, y = -1;

		while (j < N)
		{
			if (Arr[j][i] != 0)
			{
				if (fir == -1)
					fir = Arr[j][i], x = j, y = i;
				else
				{
					if (fir != Arr[j][i])
						fir = Arr[j][i], x = j, y = i;
					else
					{
						Arr[x][y] = fir * 2;
						Arr[j][i] = 0;
						fir = -1, x = -1, y = -1;
					}
				}
			}
			j++;
		}

		j = 0;

		while (j < N)
		{
			if (Arr[j][i] != 0)
			{
				ll k = j;

				while (k - 1 >= 0 && Arr[k - 1][i] == 0)
				{
					swap(Arr[k][i], Arr[k - 1][i]);
					k--;
				}
			}
			j++;
		}
	}
}
void right(vector<vector<ll>>& Arr)
{
	for (ll i = 0; i < N; i++)
	{
		ll j = N - 1, fir = -1, x = -1, y = -1;

		while (j >= 0)
		{
			if (Arr[i][j] != 0)
			{
				if (fir == -1)
					fir = Arr[i][j], x = i, y = j;
				else
				{
					if (fir != Arr[i][j])
						fir = Arr[i][j], x = i, y = j;
					else
					{
						Arr[x][y] = fir * 2;
						Arr[i][j] = 0;
						fir = -1, x = -1, y = -1;
					}
				}
			}
			j--;
		}

		j = N - 1;

		while (j >= 0)
		{
			if (Arr[i][j] != 0)
			{
				ll k = j;

				while (k + 1 < N && Arr[i][k + 1] == 0)
				{
					swap(Arr[i][k], Arr[i][k + 1]);
					k++;
				}
			}
			j--;
		}
	}
}
void left(vector<vector<ll>>& Arr)
{
	for (ll i = 0; i < N; i++)
	{
		ll j = 0, fir = -1, x = -1, y = -1;

		while (j < N)
		{
			if (Arr[i][j] != 0)
			{
				if (fir == -1)
					fir = Arr[i][j], x = i, y = j;
				else
				{
					if (fir != Arr[i][j])
						fir = Arr[i][j], x = i, y = j;
					else
					{
						Arr[x][y] = fir * 2;
						Arr[i][j] = 0;
						fir = -1, x = -1, y = -1;
					}
				}
			}
			j++;
		}

		j = 0;

		while (j < N)
		{
			if (Arr[i][j] != 0)
			{
				ll k = j;

				while (k - 1 >= 0 && Arr[i][k - 1] == 0)
				{
					swap(Arr[i][k], Arr[i][k - 1]);
					k--;
				}
			}
			j++;
		}
	}
}
void down(vector<vector<ll>>& Arr)
{
	for (ll i = 0; i < N; i++)
	{
		ll j = N - 1, fir = -1, x = -1, y = -1;

		while (j >= 0)
		{
			if (Arr[j][i] != 0)
			{
				if (fir == -1)
					fir = Arr[j][i], x = j, y = i;
				else
				{
					if (fir != Arr[j][i])
						fir = Arr[j][i], x = j, y = i;
					else
					{
						Arr[x][y] = fir * 2;
						Arr[j][i] = 0;
						fir = -1, x = -1, y = -1;
					}
				}
			}
			j--;
		}

		j = N - 1;

		while (j >= 0)
		{
			if (Arr[j][i] != 0)
			{
				ll k = j;

				while (k + 1 < N && Arr[k + 1][i] == 0)
				{
					swap(Arr[k][i], Arr[k + 1][i]);
					k++;
				}
			}
			j--;
		}
	}
}

void Input()
{
	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < N; j++)
			cin >> Arr[i][j];
	}
}

void solve(ll Idx, vector<vector<ll>> V)
{
	if (Idx == 5)
	{
		for (ll i = 0; i < N; i++)
		{
			for (ll j = 0; j < N; j++)
				total = max(total, V[i][j]);
		}
		return;
	}

	vector<vector<ll>> cmp = V;

	for (ll i = 0; i < 4; i++)
	{
		if (i == 0) up(V);
		if (i == 1) down(V);
		if (i == 2) right(V);
		if (i == 3) left(V);
		solve(Idx + 1, V);
		V = cmp;
	}
}

int main()
{
	Arr.resize(21, vector<ll>(21, 0));

	Input();

	solve(0, Arr);

	cout << total << '\n';
}