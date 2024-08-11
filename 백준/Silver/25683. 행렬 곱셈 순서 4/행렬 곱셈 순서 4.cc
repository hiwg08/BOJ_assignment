#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll n, ans;

vector<pll> V;

int main()
{
	cin >> n; V.resize(n);

	for (ll i = 0; i < n; i++)
		cin >> V[i].x >> V[i].y;

	// n >= 2

	ll L = V[n - 1].x, R = V[n - 1].y;

	for (ll i = n - 2; i >= 0; i--)
	{
		ans += (V[i].x * L * R);

		L = V[i].x;
	}

	cout << ans;
}