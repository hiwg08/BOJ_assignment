#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll K;

bool flag = false;

ll egg[4]{ 0 };

void solve() // 홀수일 때 작성.
{
	while (true)
	{
		vector<pll> V;

		for (ll i = 0; i < 4; i++)
			V.push_back({ egg[i], i });

		sort(V.begin(), V.end());

		ll cnt = V[0].x + V[1].x + V[2].x;

		if (cnt % 2 == 0)
		{
			if (V[0].x == 0 && V[1].x == V[2].x)
			{
				if (V[1].x != 0)
				{
					egg[V[1].y]--;
					egg[V[2].y]--;
					egg[V[3].y] += 2;

					for (ll j = 0; j < 4; j++)
						cout << egg[j] << " ";
					cout << '\n';
				}

				if (egg[V[0].y] == 0 && egg[V[1].y] == 0 && egg[V[2].y] == 0)
					break;
			}
			else
			{
				if (V[0].x + V[1].x >= V[2].x)
				{
					egg[V[1].y]--;
					egg[V[2].y]--;
					egg[V[3].y] += 2;

					for (ll j = 0; j < 4; j++)
						cout << egg[j] << " ";
					cout << '\n';
				}
				else
				{
					egg[V[0].y]++;
					egg[V[1].y]++;
					egg[V[2].y] -= 2;

					for (ll j = 0; j < 4; j++)
						cout << egg[j] << " ";
					cout << '\n';
				}
			}
		}
		else
		{
			egg[V[0].y] += 2;
			egg[V[2].y]--;
			egg[V[3].y]--;

			for (ll j = 0; j < 4; j++)
				cout << egg[j] << " ";
			cout << '\n';
		}
	}
}

int main()
{
	cin >> K;

	for (ll i = 0; i < 4; i++)
		cin >> egg[i];

	cout << egg[0] << " " << egg[1] << " " << egg[2] << " " << egg[3] << '\n';

	solve();
}