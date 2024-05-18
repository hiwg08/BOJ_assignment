#include <bits/stdc++.h>

using namespace std;

string S;

int main()
{
	int ans = 0;

	getline(cin, S);

	if (S.size() == 1 && S[0] == ' ')
	{
		cout << 0;
		exit(0);
	}

	int L = 0, R = (int)S.size() - 1;

	if (S[L] == ' ') L++;

	if (S[R] == ' ') R--;

	for (; L <= R; L++)
	{
		if (S[L] == ' ') ans++;
	}

	cout << ans + 1;
}