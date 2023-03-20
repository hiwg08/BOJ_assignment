#include <bits/stdc++.h>

using namespace std;

long long T;

long long N;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		cout << !(N % 10) << '\n';
	}
}