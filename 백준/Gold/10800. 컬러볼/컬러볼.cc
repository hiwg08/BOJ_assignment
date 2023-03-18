#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define pb push_back

using namespace std;

vector<pair<pll, ll>> V;

ll N;

vector<pll> color_coll[200001];

vector<pll> S;

ll ans[200001]{ 0 };

void Init()
{
	for (ll i = 1; i <= 200000; i++)
		color_coll[i].pb({ -1, 0 });

	S.pb({ -1, 0 });
}

bool cmp(pair<pll, ll> a, pair<pll, ll> b)
{
	if (a.x.x == b.x.x)
		return a.x.y < b.x.y;
	return a.x.x < b.x.x;
}

int main()
{
	fastio;

	cin >> N; V.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> V[i].x.y >> V[i].x.x;
		V[i].y = i;
	}

	sort(V.begin(), V.end(), cmp);

	Init();

	for (ll i = 0; i < N; i++)
	{
		if (S.back().x != V[i].x.x)
			S.pb({ V[i].x.x, S.back().y + V[i].x.x });
		else
			S.back().y += V[i].x.x;

		if (color_coll[V[i].x.y].back().x != V[i].x.x)
			color_coll[V[i].x.y].pb({V[i].x.x, color_coll[V[i].x.y].back().y + V[i].x.x});
		else
			color_coll[V[i].x.y].back().y += V[i].x.x;
		
		ll L = S[(ll)S.size() - 2].y, R = color_coll[V[i].x.y][(ll)color_coll[V[i].x.y].size() - 2].y;

		ans[V[i].y] = L - R;
	}

	for (ll i = 0; i < N; i++)
		cout << ans[i] << '\n';
}