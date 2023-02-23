#include <bits/stdc++.h>
#define MOD 80

using namespace std;

int N;

string S = "", Ans = "";

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char C; cin >> C;
		S += C;
	}

	int lo = 0, hi = (int)S.length() - 1;

	while (lo <= hi)
	{
		if (S[lo] < S[hi])
			Ans += S[lo++];
		else if (S[lo] > S[hi])
			Ans += S[hi--];
		else
		{
			if (lo == hi)
				Ans += S[lo++];
			else
			{
				int tmp_lo = lo, tmp_hi = hi;

				while (tmp_lo <= tmp_hi)
				{
					if (S[tmp_lo] == S[tmp_hi])
					{
						tmp_lo++;
						tmp_hi--;
					}
					else if (S[tmp_lo] < S[tmp_hi])
					{
						Ans += S[lo++];
						break;
					}
					else
					{
						Ans += S[hi--];
						break;
					}
				}

				if (tmp_lo > tmp_hi)
					Ans += S[lo++];
			}
		}
	}

	for (int i = 0; i < (int)Ans.length(); i++)
	{
		cout << Ans[i];
		if ((i + 1) % MOD == 0)
			cout << '\n';
	}
}