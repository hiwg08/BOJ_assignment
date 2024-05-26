#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K, T;

ll arr[200'001]{ 0 };

stack<ll> stk;

int main()
{
	cin >> N >> K >> T;

	for (ll i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (ll i = 0; i < N; i++)
	{
		if (arr[i] < T)
		{
			stk.push(arr[i]);
			continue;
		}
			
		while (K > 0 && !stk.empty())
		{
			T += stk.top();
			stk.pop();

			K--;

			if (arr[i] < T)
			{
				stk.push(arr[i]);
				break;
			}
		}
	}

	while (K > 0 && !stk.empty())
	{
		T += stk.top();
		stk.pop();

		K--;
	}

	cout << T;
}