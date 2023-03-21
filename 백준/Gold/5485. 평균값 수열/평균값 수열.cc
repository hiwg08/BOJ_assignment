#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;

ll a, b, L, R;

int main()
{
	cin >> N;

	cin >> a >> b;

	L = b, R = 2 * b - a;

	for (ll i = 2, c; i < N; i++)
	{
		cin >> c;

		ll new_L = max(2 * c - R, c), new_R = 2 * c - L;
		L = new_L, R = new_R;
	}

	cout << max(R - L + 1, (ll)0) << '\n';
}