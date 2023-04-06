#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll N;

vector<ll> V;

vector<ll> ori;

bool check(ll a, ll b)
{
	long double ra = sqrt(a), rb = sqrt(b);

	return !(ra - (ll)ra > 0 || rb - (ll)rb > 0);
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		ori.push_back(a);
		V.push_back(a);
	}

	sort(V.begin(), V.end());

	for (ll i = 0; i < N; i++)
	{
		ll cha = V[i];

		if (cha == ori[i])
			continue;

		else
		{
			ll ret = gcd(cha, ori[i]);

			if (!check(cha / ret, ori[i] / ret))
			{
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << "YES";
}