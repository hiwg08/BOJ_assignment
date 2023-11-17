#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, M, S, tot = LLONG_MIN;

vector<pll> V;

ll m_arr[300002]{ 0 }, s_arr[300002]{ 0 };

multiset<ll> ms;

int main()
{
	cin >> N >> M >> S; V.resize(N);

	for (ll i = 0; i < N; i++)
		cin >> V[i].x >> V[i].y;

	if (M == 0 && S == 0)
	{
		cout << 0;
		exit(0);
	}
	if (M == 0 && S != 0)
	{
		tot = 0;
		sort(V.begin(), V.end(), [&](pll a, pll b) {
			return a.y > b.y;
		});

		for (ll i = 0; i < S; i++)
			tot += V[i].y;

		cout << tot;
		exit(0);
	}
	if (M != 0 && S == 0)
	{
		tot = 0;

		sort(V.begin(), V.end(), [&](pll a, pll b) {
			return a.x > b.x;
		});

		for (ll i = 0; i < M; i++)
			tot += V[i].x;

		cout << tot;
		exit(0);
	}

	sort(V.begin(), V.end(), [&](pll a, pll b) {
		return a.x + b.y > a.y + b.x;
	});
	
	for (ll i = 1; i <= N; i++)
	{
		m_arr[i] = m_arr[i - 1] + V[i - 1].x;

		ms.insert(V[i - 1].x);

		if ((ll)ms.size() > M)
		{
			auto it = *(ms.begin());

			m_arr[i] -= it;

			ms.erase(ms.begin());
		}
	}

	ms.clear();

	for (ll j = N; j >= 1; j--)
	{
		s_arr[j] = s_arr[j + 1] + V[j - 1].y;

		ms.insert(V[j - 1].y);

		if ((ll)ms.size() > S)
		{
			auto it = *(ms.begin());

			s_arr[j] -= it;

			ms.erase(ms.begin());
		}
	}

	for (ll i = M; i <= N - S; i++)
		tot = max(tot, m_arr[i] + s_arr[i + 1]);

	cout << tot;
}