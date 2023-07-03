#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, need, sum, total = LLONG_MAX;

vector<pll> V;

vector<ll> price;

bool cmp(pll a, pll b) // x를 무게, y를 가격
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

int main()
{
	cin >> N >> need;

	for (ll i = 0, a, b; i < N; i++) // 순서대로 무게, 가격
	{
		cin >> a >> b;
		V.push_back({ a, b });
		price.push_back(b);
		sum += a;
	}

	sort(price.begin(), price.end());

	sort(V.begin(), V.end(), cmp);

	for (ll i = 0; i < N; i++)
	{
		ll cnt = (ll)(lower_bound(price.begin(), price.end(), V[i].y + 1) - price.begin()) - (ll)(lower_bound(price.begin(), price.end(), V[i].y) - price.begin());

		while (true)
		{
			if (cnt == 0)
			{
				i--;
				break;
			}

			if (sum >= need)
				total = min(total, cnt * V[i].y);

			cnt--;
			sum -= V[i].x;
			i++;
		}
	}

	if (total == LLONG_MAX)
		total = -1;

	cout << total;
}

// 무게가 같으면? 가격은 어떻게 설정하는 게 좋을까?