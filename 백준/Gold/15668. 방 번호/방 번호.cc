#include <bits/stdc++.h>

using namespace std;

int N;

bool dp_check(int N, int& bits)
{
	while (N != 0)
	{
		int T1 = N % 10;

		if (bits & (1 << T1))
			return false;

		bits |= (1 << T1);
		N /= 10;
	}

	return true;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= 87654 && i < N; i++)
	{
		int L = i, R = N - i, bits = 0;

		if (!dp_check(L, bits))
			continue;

		if (!dp_check(R, bits))
			continue;

		cout << L << " + " << R;
		exit(0);
	}

	cout << -1;
}