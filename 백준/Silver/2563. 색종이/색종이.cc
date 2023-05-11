#include <bits/stdc++.h>

using namespace std;

int N, total;

set<pair<int, int>> ms;

int main()
{
	cin >> N;

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;

		for (int j = a * 10 + 5; j <= (a + 10) * 10 - 5; j += 10)
		{
			for (int k = b * 10 + 5; k <= (b + 10) * 10 - 5; k += 10)
				ms.insert({ j, k });
		}
	}

	cout << (int)ms.size();
}