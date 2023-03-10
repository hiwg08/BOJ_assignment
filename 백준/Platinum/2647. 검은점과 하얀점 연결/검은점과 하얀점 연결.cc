#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N;

string S;

pll DP[101][101];

ll Arr[101]{ 0 };

pair<pll, pll> trace[101][101];

vector<pll> V;

void init()
{
	for (ll i = 0; i <= 100; i++)
	{
		for (ll j = 0; j <= 100; j++)
			DP[i][j] = { -1, -1 };
	}
}

pll solve(ll L, ll R)
{
	if (L > R)
		return { 0, 0 };

	pll& ret = DP[L][R];

	if (ret.x != -1 || ret.y != -1)
		return ret;

	ret = { INT_MAX, INT_MAX };

	pll T1 = solve(L + 1, R - 1); // x에는 그 구간에서 만들어지는 최소 높이, y는 그 구간에서의 최소 길이

	if ((Arr[L] && !Arr[R]) || (!Arr[L] && Arr[R]))
	{
		ll nxt_height = T1.x + 1;

		ll nxt_length = (2 * nxt_height) + R - L + T1.y;

		if (nxt_length < ret.y)
		{
			ret.x = nxt_height;
			ret.y = nxt_length;
			trace[L][R] = { {-1, -1}, {L + 1, R - 1} };
		}
	}

	for (ll i = L + 1; i < R; i += 2) // L + i, i + 1, R을 기준으로
	{
		pll ni = solve(L, i), nj = solve(i + 1, R);

		if (ni.y + nj.y < ret.y)
		{
			ret.x = max(ni.x, nj.x);
			
			ret.y = ni.y + nj.y;

			trace[L][R] = { {L, i}, {i + 1, R} };
		}
	}

	return ret;
}

void reconstruct(ll L, ll R)
{
	if (L > R)
		return;

	auto ni = trace[L][R];

	if (ni.x.x == -1 && ni.x.y == -1)
	{
		V.push_back({ L + 1, R + 1 });
		reconstruct(ni.y.x, ni.y.y);
		return;
	}
	reconstruct(ni.x.x, ni.x.y);
	reconstruct(ni.y.x, ni.y.y);
}

int main()
{
	cin >> N;

	cin >> S;

	for (ll i = 0; i < N; i++)
		Arr[i] = S[i] - '0';

	init();

	cout << solve(0, N - 1).y << '\n';

	reconstruct(0, N - 1);

	sort(V.begin(), V.end());

	for (auto e : V)
		cout << e.x << " " << e.y << '\n';
}