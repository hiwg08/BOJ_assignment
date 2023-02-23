#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll N, Sum, MAX = LLONG_MIN;

bool CHK = false;

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0, a; i < N; i++)
	{
		cin >> a;
		Sum += a;
		MAX = max(MAX, a);
	}

	if (Sum % 2 == 0)
		CHK = true;

	Sum -= MAX;

	if (Sum <= MAX)
		cout << MAX - Sum << '\n';
	else
		CHK ? cout << 0 << '\n' : cout << 1 << '\n';

}