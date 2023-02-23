#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, total;

deque<ll> pos, neg;

bool zero = false;

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;

		if (a > 0) pos.push_back(a);
		else if (a < 0) neg.push_back(a);
		else zero = true;
	}

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());

	while ((ll)neg.size() > 1)
	{
		ll L = neg.front(); neg.pop_front();
		ll R = neg.front(); neg.pop_front();
		total += L * R;
	}

	while ((ll)pos.size() > 1)
	{
		ll L = pos[(ll)pos.size() - 1]; ll R = pos[(ll)pos.size() - 2];
		if (L == 1 || R == 1)
			break;
		total += L * R;
		pos.pop_back(); pos.pop_back();
	}

	while (!pos.empty())
	{
		total += pos.front();
		pos.pop_front();
	}

	if ((ll)neg.size() == 1)
	{
		if (!zero)
			total += neg.front();
	}

	cout << total << '\n';
}