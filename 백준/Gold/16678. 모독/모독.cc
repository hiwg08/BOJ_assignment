#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, total;

vector<ll> Arr;

void solve()
{
	ll standard = 1;

	for (ll i = 0; i < N; i++)
	{
		if (Arr[i] > standard)
			total += Arr[i] - standard;

		else if (Arr[i] < standard)
			standard--;

		standard++;
	}
}

int main()
{
	cin >> N; Arr.resize(N);

	for (auto& iv : Arr)
		cin >> iv;

	sort(Arr.begin(), Arr.end());

	solve();

	cout << total;
}