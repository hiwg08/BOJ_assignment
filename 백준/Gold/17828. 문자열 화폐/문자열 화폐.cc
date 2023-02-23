#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, X;

string Ans = "";

int main()
{
	cin >> N >> X;

	if (X < N || X > 26 * N)
	{
		cout << "!" << '\n';
		exit(0);
	}

	for (ll i = N; i >= 1; i--)
	{
		ll nxt = X - 26;

		ll n_L = (i - 1), n_R = (i - 1) * 26;

		if (nxt < n_L || nxt > n_R) 
		{
			Ans += (char)(X - (i - 1) + 64);
			X -= X - (i - 1);
		}
		else
		{
			Ans += 'Z';
			X -= 26;
		}
	}

	reverse(Ans.begin(), Ans.end());

	cout << Ans << '\n';
}