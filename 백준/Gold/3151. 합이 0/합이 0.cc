#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define ll long long

using namespace std;

ll N, Ans;

vector<ll> Arr;

ll Comb(ll N)
{
	return (N * (N - 1)) / 2;
}

ll Make_Case(ll S, ll E, ll par)
{
	ll SUM = 0;

	while (S < E)
	{
		if (Arr[S] + Arr[E] > par) E--;
		else if (Arr[S] + Arr[E] < par) S++;
		else
		{
			if (Arr[S] == Arr[E])
			{
				SUM += Comb(E - S + 1);
				break;
			}

			ll L = 1, R = 1;

			while (S + 1 < E && Arr[S] == Arr[S + 1])
			{
				S++; L++;
			}
			while (E - 1 > S && Arr[E] == Arr[E - 1])
			{
				E--; R++;
			}

			S++; E--;
			SUM += L * R;
		}
	}

	return SUM;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
	{
		ll a; cin >> a;
		Arr.push_back(a);
	}

	sort(all(Arr));

	for (ll i = 0; i < N; i++)
		Ans += Make_Case(i + 1, N - 1, -Arr[i]);

	cout << Ans << '\n';
}