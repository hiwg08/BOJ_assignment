#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin >> T;

	while (T--)
	{
		int a; cin >> a;

		if (a <= 3 || a == 6)
			cout << 0 << '\n';
		else if (a == 4)
			cout << 2 << '\n';
		else
			cout << 1 << '\n';
	}
}