// my answer
// sol : math + divide and conquer
// time complexity : O(NlogN)

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vl vector<ll>
#define pb push_back
#define o (ll)1
#define x first
#define y second

using namespace std;

ll N, M;

ll ans[500001]{ 0 };

void solve(vl a, vl b, ll pos)
{
	if ((ll)a.size() == 1)
	{
		ans[a[0]] = b[0];
		return;
	}

	vl la, lb, ra, rb;

	if (((ll)a.size() & 1) == 1)
	{
		if ((b[0] & pos) == pos) // 홀수일 때
		{
			for (ll i = 1; i < (ll)a.size(); i += 2)
			{
				la.pb(a[i]);
				lb.pb(b[i + 1]);
			}
			
			ra.pb(a[0]);
			rb.pb(b[0]);

			for (ll i = 2; i < (ll)a.size(); i += 2)
			{
				ra.pb(a[i]);
				rb.pb(b[i - 1]);
			}
		}
		else
		{
			for (ll i = 0; i < (ll)a.size(); i += 2)
			{
				la.pb(a[i]);
				lb.pb(b[i]);
			}
			for (ll i = 1; i < (ll)a.size(); i += 2)
			{
				ra.pb(a[i]);
				rb.pb(b[i]);
			}
		}
	}
	else
	{
		for (ll i = 0; i < (ll)a.size(); i += 2)
		{
			la.pb(a[i]);
			(b[0] & pos) == pos ? lb.pb(b[i + 1]) : lb.pb(b[i]);
		}

		for (ll i = 1; i < (ll)a.size(); i += 2)
		{
			ra.pb(a[i]);
			(b[0] & pos) == pos ? rb.pb(b[i - 1]) : rb.pb(b[i]);
		}
	}

	solve(la, lb, pos << 1);
	solve(ra, rb, pos << 1);
}

int main()
{
	fastio;

	cin >> N >> M;

	vl a, b;

	for (ll i = 0; i <= N - 1; i++)
		a.pb(i), b.pb(i + M);

	solve(a, b, 1);

	for (ll i = 0; i <= N - 1; i++)
		cout << i << " " << ans[i] << '\n';
}
