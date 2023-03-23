#include <bits/stdc++.h>

using namespace std;

int N, K;

vector<int> V;

int main()
{
	cin >> N >> K;

	if (N == K)
	{
		cout << "Impossible";
		exit(0);
	}

	for (int i = 1; i <= N; i++)
		V.push_back(i);

	K = N - K;

	int start = 0;

	if (K % 2 != 0)
		K--, start++;

	while (K != 0)
	{
		int nxt = start + 1;

		if (nxt >= (int)V.size())
			break;

		swap(V[start], V[nxt]);

		start += 2;

		K -= 2;
	}

	for (auto e : V)
		cout << e << " ";
}