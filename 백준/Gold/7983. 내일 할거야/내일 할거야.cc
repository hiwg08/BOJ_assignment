#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, ans;

vector<pll> V;

bool cmp(pll a, pll b)
{
	return a.y > b.y;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		V.push_back({ b - a + 1, b });
	}

	sort(V.begin(), V.end(), cmp);

	ans = V[0].x - 1;

	for (ll i = 1; i < N; i++) // 아예 값을 업데이트 해가면서 진행해야 한다.
	{
		ll Interval = V[i].y - V[i].x;

		if (V[i].y >= V[i - 1].x)
			V[i].y = V[i - 1].x - 1, V[i].x = V[i].y - Interval;
		
		ans = V[i].x - 1;
	}

	cout << ans << '\n';
}