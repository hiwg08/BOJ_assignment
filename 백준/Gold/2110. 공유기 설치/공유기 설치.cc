#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAX 1000000000
using namespace std;

ll N, C, Arr[200001]{ 0 };

bool CHK(ll distance)
{
	ll Cnt = 1, Start = Arr[0];

	for (ll i = 1; i < N; i++)
	{
		if (Arr[i] - Start >= distance)
		{
			Cnt++;
			Start = Arr[i];
		}
	}

	return Cnt >= C;
}

ll Binary_Search()
{
	ll lo = 1, hi = MAX + 1;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) / 2;

		CHK(mid) ? lo = mid : hi = mid;
	}

	return lo;
}

int main()
{
	fastio;

	cin >> N >> C;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	cout << Binary_Search() << '\n';
}