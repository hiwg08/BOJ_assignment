#include <bits/stdc++.h>

using namespace std;

string A, B, tmp;

int n;

bool check(int interval)
{
	for (int i = interval; i < n; i++)
	{
		if (tmp[i] - tmp[i - interval] != 0)
			return false;
	}
	return true;
}

void solve()
{
	int idx = INT_MAX;

	for (int i = 1; i * i <= n; i++)
	{
		if (n % i)
			continue;

		if (check(i))
			idx = min(idx, i);

		if (check(n / i))
			idx = min(idx, n / i);
	}

	for (int i = 0; i < idx; i++)
		cout << tmp[i];
}

int main()
{
	cin >> A;
	cin >> B;

	n = (int)A.length();

	for (int i = 0; i < n; i++)
	{
		if (A[i] < B[i])
			tmp += B[i] - A[i] + 'A' - 1;

		else if (A[i] == B[i])
			tmp += 'Z';

		else
			tmp += 26 + B[i] - A[i] + 'A' - 1;
	}

	solve();
}