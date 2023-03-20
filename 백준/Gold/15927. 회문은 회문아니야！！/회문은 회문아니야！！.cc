#include <bits/stdc++.h>

using namespace std;

string S;

int main() // order(N)
{
	cin >> S;

	char c = S[0];

	bool chk = true, is_p = true;

	for (int i = 1; i < (int)S.size(); i++)
	{
		if (c != S[i])
		{
			chk = false;
			break;
		}
	}

	int lo = 0, hi = (int)S.size() - 1;

	while (lo <= hi)
	{
		if (S[lo] != S[hi])
		{
			is_p = false;
			break;
		}
		lo++, hi--;
	}

	if (is_p) // 펠린드롬이 맞으면
	{
		chk ? cout << -1 : cout << (int)S.size() - 1;
		cout << '\n';
	}
	else
		cout << (int)S.size() << '\n';
}