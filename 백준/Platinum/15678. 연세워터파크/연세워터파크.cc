#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, D, total = LLONG_MIN;

deque<pll> DQ;

int main()
{
	fastio;

	cin >> N >> D;

	for (ll i = 1, a; i <= N; i++)
	{
		cin >> a;

		ll maxi = -1;

		if (DQ.empty())
			maxi = a;
		else
			maxi = max(DQ.front().y + a, a);
			
		while (!DQ.empty() && DQ.back().y <= maxi)
			DQ.pop_back();

		DQ.push_back({ i, maxi });

		total = max(total, DQ.front().y);

		while (!DQ.empty() && DQ.front().x <= i - D)
			DQ.pop_front();
	} 

	cout << total;
}