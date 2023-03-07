#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, chk;

ll Arr[4200000]{ 0 };

pll solve(ll Idx)
{
	if (Idx >= chk)
		return { 0, 0 };

	pll ret = { 0, 0 };

	ll lo = 2 * Idx + 1, hi = 2 * Idx + 2;

	pll L = solve(lo), R = solve(hi);

	ret.x = max(Arr[lo] + L.x, Arr[hi] + R.x);

	ret.y = L.y + R.y + Arr[lo] + Arr[hi] + abs((Arr[lo] + L.x) - (Arr[hi] + R.x));

	return ret;
}

int main()
{
	fastio;

	cin >> N;

	chk = (ll)pow(2, N);

	for (ll i = 1; i <= (ll)pow(2, N + 1) - 2; i++)
		cin >> Arr[i];

	cout << solve(0).y << '\n';
}