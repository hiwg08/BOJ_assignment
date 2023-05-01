#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

map<string, pair<ll, ll>> V;

string Arr[]{ "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

string A, B, C;

ll ans = 0;

void init()
{
	for (ll i = 0; i < 10; i++)
		V[Arr[i]] = { i, (ll)(pow(10, i)) };
}

int main()
{
	init();

	cin >> A >> B;

	ans = V[A].x * 10 + V[B].x;

	cin >> C;

	cout << ans * V[C].y;
}