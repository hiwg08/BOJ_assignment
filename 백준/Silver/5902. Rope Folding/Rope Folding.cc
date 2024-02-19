#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll cnt[10101]{ 0 };

vector<ll> arr;

ll N, L, ans;

ll mx = -1, my = 20000;

int main()
{
	cin >> N >> L;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		arr.push_back(a);
		cnt[a] = 1;
		mx = max(mx, a), my = min(my, a);
	}

	sort(arr.begin(), arr.end());

	ll Idx = 0;

	for (ll i = 0; i < (ll)arr.size() - 1; i++)
	{
		ll L = i, R = i + 1;

		ll chk = arr[L] + arr[R];

		bool flag = true;

		while (true)
		{
			L--, R++;

			if (L < 0 || R >= (ll)arr.size())
				break;

			if (chk != arr[L] + arr[R])
			{
				flag = false;
				break;
			}
		}

		if (flag) ans++;

		flag = true;

		L = i, R = i;

		while (true)
		{
			L--, R++;

			if (L < 0 || R >= (ll)arr.size())
				break;

			if (arr[i] - arr[L] != arr[R] - arr[i])
			{
				flag = false;
				break;
			}
		}

		if (flag && i != 0) ans++;
	}

	cout << ans;
}