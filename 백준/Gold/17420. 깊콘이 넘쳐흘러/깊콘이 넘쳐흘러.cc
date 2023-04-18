#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, total;

multiset<ll> ms[100001];

ll remain[100001]{ 0 };

vector<pll> V;

vector<ll> comp;

bool cmp(pll a, pll b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

void input()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> remain[i];

	V.push_back({ 0, 0 });

	comp.push_back(0);

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		V.push_back({ remain[i], a });
		comp.push_back(-a);
	}

	sort(V.begin(), V.end(), cmp);

	sort(comp.begin(), comp.end());

	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	ll Idx = (ll)(lower_bound(comp.begin(), comp.end(), 0) - comp.begin());

	ms[Idx].insert(0);
}

int main()
{
	input();

	for (ll i = 1; i < N + 1; i++)
	{
		ll ni = V[i].x, nj = V[i].y;

		ll Idx = (ll)(lower_bound(comp.begin(), comp.end(), -V[i].y) - comp.begin());

		ll nxt = (ll)(lower_bound(comp.begin(), comp.end(), -V[i].y + 1) - comp.begin()); // 전에 있던 값의 '최댓값'

		auto it = ms[nxt].end();

		it--;

		auto maxi = *it; // maxi가 곧 최댓값을 의미한다.
	
		if (nj >= ni)
		{
			ll quo = (nj - ni) / 30;
			ll remain = (nj - ni) % 30;
			ll R = 0, q = 0;

			if (remain == 0)
			{
				R = 30 * quo + ni;
				total += quo;
			}
			else
			{
				R = 30 * (quo + 1) + ni;
				total += quo + 1;
			}

			q = R;

			if (maxi >= R)
			{
				quo = (maxi - R) / 30;
				remain = (maxi - R) % 30;

				if (remain == 0)
				{
					q = 30 * quo + R;
					total += quo;
				}
				else
				{
					q = 30 * (quo + 1) + R;
					total += quo + 1;
				}
					
			}

			ms[Idx].insert(q);
		}
		else
		{
			ll q = ni;

			if (maxi >= ni)
			{
				ll quo = (maxi - ni) / 30;
				ll remain = (maxi - ni) % 30;

				if (remain == 0)
				{
					q = 30 * quo + ni;
					total += quo;
				}
					
				else
				{
					q = 30 * (quo + 1) + ni;
					total += quo + 1;
				}
				
			}

			ms[Idx].insert(q);
		}
	}

	cout << total;
}