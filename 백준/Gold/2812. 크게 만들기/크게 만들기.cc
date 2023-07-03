#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, limi;

string S;

vector<ll> ST;

int main()
{
	cin >> N >> K;

	cin >> S;

	for (ll i = 0; i < N; i++)
	{
		ll J = (ll)(S[i] - '0');

		while (limi < K && (!ST.empty() && ST.back() < J))
		{
			ST.pop_back();
			limi++;
		}

		ST.push_back(J);
	}

	while (!ST.empty() && limi < K)
	{
		ST.pop_back();
		limi++;
	}
	
	for (auto e : ST)
		cout << e;
}