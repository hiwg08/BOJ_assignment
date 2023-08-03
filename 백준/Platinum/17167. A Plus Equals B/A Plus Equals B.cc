#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define o (ll)1

using namespace std;

ll A, B;

string sta[]{ "A+=A", "A+=B", "B+=A", "B+=B" };

vector<ll> V;

void solve()
{
	while (A != B)
	{
		ll T1 = A & (-A);
		ll T2 = B & (-B);

		if (T1 > T2)
		{
			for (ll i = 0; i < (ll)(log2(T1 / T2)); i++)
				V.push_back(3);
		}
		else if (T1 < T2)
		{
			for (ll i = 0; i < (ll)(log2(T2 / T1)); i++)
				V.push_back(0);
		}
		
		A >>= (ll)(log2(T1)), B >>= (ll)(log2(T2));
	
		if (A < B)
		{
			B += A;
			V.push_back(2);
		}
		else if (A > B)
		{
			A += B;
			V.push_back(1);
		}
	}
}

int main()
{
	fastio;

	cin >> A >> B;

	solve();

	cout << (ll)V.size() << '\n';
	
	for (auto e : V)
		cout << sta[e] << '\n';
}