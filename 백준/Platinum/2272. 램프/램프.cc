#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll Arr[1000001]{ 0 }, tmp[1000001]{ 0 };

ll N, M;

void solve()
{
	for (ll j = 1; j <= M; j <<= 1)
	{
		if (M & j)
		{
			for (ll i = 0; i < N; i++)
				tmp[i] = Arr[i] ^ Arr[(i + j) % N];
			for (ll i = 0; i < N; i++)
				Arr[i] = tmp[i];
		}
	}
}

int main()
{
	fastio;

	cin >> N >> M;

	for (ll i = 0; i < N; i++) 
		cin >> Arr[i];

	solve();

	for (ll i = 0; i < N; i++)
		cout << Arr[i] << '\n';
}