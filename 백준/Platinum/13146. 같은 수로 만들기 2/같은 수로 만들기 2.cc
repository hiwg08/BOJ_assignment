#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, Ans;

stack<ll> V;

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;

		bool CHK = false;

		while (!V.empty() && V.top() < a)
		{
			if (!CHK)
			{
				CHK = true;
				Ans += a - V.top();
			}
			V.pop();
		}

		V.push(a);
	}

	while (V.size() > 1)
	{
		ll L1 = V.top(); V.pop();
		ll L2 = V.top(); V.pop();
		Ans += (L2 - L1);
		V.push(L2);
	}
	
	cout << Ans << '\n';
}