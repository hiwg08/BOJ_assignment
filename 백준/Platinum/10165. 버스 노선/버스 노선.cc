#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, cnt;

vector<pair<pll, ll>> V;

vector<ll> ans;

bool cmp(pair<pll, ll> a, pair<pll, ll> b)
{
	if (a.x.x == b.x.x)
		return a.x.y > b.x.y;
	return a.x.x < b.x.x;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (ll i = 0, a, b; i < M; i++)
	{
		cin >> a >> b;

		if (a > b) // 엇갈리는 경우
			V.push_back({ { a, b + N }, i + 1 });
		else
		{
			V.push_back({ { a, b }, i + 1 });
			V.push_back({ { a + N, b + N }, i + 1 });
		}		
	}

	sort(V.begin(), V.end(), cmp);

	ll c_x = V[0].x.x, c_y = V[0].x.y;

	for (ll i = 1; i < (ll)V.size(); i++)
	{
		ll ni = V[i].x.x, nj = V[i].x.y;
		
		if (nj > c_y)
			c_x = ni, c_y = nj;
		else
			ans.push_back(V[i].y);
	}

	sort(ans.begin(), ans.end());

	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (ll i = 1; i <= M; i++)
	{
		ll nxt = (ll)(lower_bound(ans.begin(), ans.end(), i) - ans.begin());

		if (nxt < (ll)ans.size() && ans[nxt] == i)
			continue;
		cout << i << " ";
	}
}