#include <bits/stdc++.h>

using namespace std;

string S;

int DP[501][501]{ 0 };

int solve(int Start, int End)
{
	if (Start >= End)
		return 0;

	int& ret = DP[Start][End];

	if (ret != -1)
		return ret;

	ret = 0;

	if ((S[Start] == 'a' && S[End] == 't') || (S[Start] == 'g' && S[End] == 'c'))
		ret = solve(Start + 1, End - 1) + 2;

	for (int i = Start; i <= End; i++)
		ret = max(ret, solve(Start, i) + solve(i + 1, End));

	return ret;
}

int main()
{
	cin >> S;

	memset(DP, -1, sizeof(DP));

	cout << solve(0, (int)S.length() - 1) << '\n';
}