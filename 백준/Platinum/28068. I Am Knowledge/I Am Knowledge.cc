#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, money;

vector<pll> ine, dee;

void sta_1()
{
	sort(ine.begin(), ine.end(), [&](pll a, pll b) {
		if (a.x == b.x)
			return a.y > b.y;
		return a.x < b.x;
	});

	for (ll i = 0; i < (ll)ine.size(); i++)
	{
		if (money < ine[i].x)
		{
			cout << 0;
			exit(0);
		}
		money += (-ine[i].x + ine[i].y);
	}
}

void sta_2()
{
	sort(dee.begin(), dee.end(), [&](pll a, pll b) 
	{
		if (a.y == b.y)
			return a.x < b.x;
		return a.y > b.y;
	});

	for (ll i = 0; i < (ll)dee.size(); i++)
	{
		if (money < dee[i].x)
		{
			cout << 0;
			exit(0);
		}
		money += (-dee[i].x + dee[i].y);
	}
}

int main()
{
	cin >> N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;

		if (a == 0)
			money += b;

		else
			a > b ? dee.push_back({ a, b }) : ine.push_back({ a, b });
	}

	sta_1();

	sta_2();

	cout << 1;
}