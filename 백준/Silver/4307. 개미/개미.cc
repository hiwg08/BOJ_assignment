#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin >> T;

	while (T--)
	{
		int a, b; cin >> a >> b;

		int L = 0, R = 0;

		for (int i = 0; i < b; i++)
		{
			int c; cin >> c;

			L = max(L, min(c, a - c));
			R = max(R, max(c, a - c));
		}

		cout << L << " " << R << '\n';
	}
}