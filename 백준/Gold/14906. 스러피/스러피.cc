#include <bits/stdc++.h>

using namespace std;

int T;

bool is_slump(string S)
{
	int len = (int)S.length();

	if (len < 2)
		return false;
	if (len == 2)
		return S == "DF" || S == "EF";

	bool ret = true;

	if (len >= 3)
	{
		string Mid = S.substr(1, len - 2);

		for (auto e : Mid)
		{
			if (e != 'F')
			{
				ret = false;
				break;
			}
		}

		if (ret)
			return ((S[0] == 'D' && S[len - 1] == 'G') || (S[0] == 'E' && S[len - 1] == 'G') || 
				(S[0] == 'D' && S[len - 1] == 'F') || (S[0] == 'E' && S[len - 1] == 'F'));
	}

	for (int i = 1; i < len - 2; i++)
	{
		string L = S.substr(0, i + 1), R = S.substr(i + 1, len - 1);
	
		ret = is_slump(L) && is_slump(R);

		if (ret) break;
	}

	return ret;
}

bool is_slimp(string S)
{
	int len = (int)S.length();

	if (len <= 1)
		return false;
	if (len == 2)
		return S == "AH";

	if (S[0] == 'A' && S[1] == 'B' && S[len - 1] == 'C')
		return is_slimp(S.substr(2, len - 3));
	if (S[0] == 'A' && S[len - 1] == 'C')
		return is_slump(S.substr(1, len - 2));
	return false;
}

int main()
{
	cin >> T;

	cout << "SLURPYS OUTPUT" << '\n';

	while (T--)
	{
		string S; cin >> S;

		int len = (int)S.length();

		bool CHK = false;

		for (int i = 1; i < len - 2; i++)
		{
			string L = S.substr(0, i + 1), R = S.substr(i + 1, len - 1);

			if (is_slimp(L) && is_slump(R))
			{
				CHK = true;
				break;
			}
		}

		CHK ? cout << "YES" << '\n' : cout << "NO" << '\n';
	}

	cout << "END OF OUTPUT" << '\n';
}