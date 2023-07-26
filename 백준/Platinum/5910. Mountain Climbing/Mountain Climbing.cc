#include <bits/stdc++.h>
#define all(p) (p).begin(), (p).end()
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, FD, total;

vector<pll> UD[2];

void solve(bool fl)
{
	for (ll i = 0; i < (ll)UD[fl].size(); i++)
	{
		if (FD <= UD[fl][i].x)
			FD = UD[fl][i].y;
		else
			FD += (-UD[fl][i].x + UD[fl][i].y);
	}
}

int main()
{
	cin >> N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;

		total += a;

		a <= b ? UD[0].push_back({a, b}) : UD[1].push_back({a, b});
	}

	sort(all(UD[0]), [&](pll a, pll b) {
		return a.x < b.x;
	});

	sort(all(UD[1]), [&](pll a, pll b) {
		return a.y > b.y;
	});

	solve(false);

	solve(true);

	total += FD;

	cout << total;
}