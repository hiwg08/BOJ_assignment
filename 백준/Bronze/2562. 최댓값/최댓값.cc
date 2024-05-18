#include <bits/stdc++.h>

using namespace std;

int main()
{
	int maxi = 0, Idx = 0;

	for (int i = 1, a; i <= 9; i++)
	{
		cin >> a;

		if (a > maxi)
		{
			maxi = a;
			Idx = i;
		}
	}

	cout << maxi << '\n' << Idx;
}