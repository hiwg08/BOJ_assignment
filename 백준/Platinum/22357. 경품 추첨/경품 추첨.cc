#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll K, N;

bool vis[3000]{ 0 };

vector<ll> coll;

void eratos()
{
	for (ll i = 2; i <= (ll)(sqrt(2500)); i++)
	{
		if (vis[i])
			continue;
		for (ll j = i; j <= (ll)2500; j += i)
		{
			if (j != i)
				vis[j] = true;
		}
	}
}

int main()
{
	cin >> K >> N;

	eratos();

	for (ll i = 2; i <= 2500; i++)
	{
		if (!vis[i] && i >= N)
		{
			coll.push_back(i);

			if ((ll)coll.size() >= K)
				break;
		}
	}

	for (ll i = 0; i < K; i++)
	{
		for (ll q = 1, Idx = 0; Idx < N; q += coll[i], Idx++)
			cout << q << " ";
		cout << '\n';
	}
}