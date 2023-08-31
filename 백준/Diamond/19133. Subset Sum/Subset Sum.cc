// refered to https://blog.naver.com/jinhan814/223156528218
// to practice the sum of subset

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

ll N, K, total;

priority_queue<pll, vector<pll>, greater<>> PQ;

ll Arr[200001]{ 0 };

int main()
{
	cin >> N >> K;

	for (ll i = 0; i < N; i++)
	{
		cin >> Arr[i];

		if (Arr[i] < 0)
		{
			total += Arr[i];
			Arr[i] = -Arr[i];
		}
	}

	sort(Arr, Arr + N);

	bool flag = true;

	if (total < 0)
	{
		K--;
		flag = false;
		cout << total << '\n';
	}

	PQ.push({ Arr[0], 0 });

	while (K > 0)
	{
		if (!PQ.empty())
		{
			pll T1 = PQ.top();
			PQ.pop();

			if (total + T1.x == 0 && !flag)
				flag = true;
			else
			{
				cout << total + T1.x << '\n';
				K--;
			}
				
			if (T1.y + 1 < N)
			{
				PQ.push({ T1.x - Arr[T1.y] + Arr[T1.y + 1], T1.y + 1 });
				PQ.push({ T1.x + Arr[T1.y + 1], T1.y + 1 });
			}
		}
	}
}