#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[50001]{ 0 }, total, ins, Ans = INT_MIN;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		total += Arr[i];
	}

	int lo = 0, hi = 0;

	ins = Arr[lo];

	Ans = max(Ans, min(ins, total - ins));

	while (hi < N)
	{
		if (ins <= total - ins)
		{
			hi++;
			
			if (hi < N)
			{
				ins += Arr[hi];
				Ans = max(Ans, min(ins, total - ins));
			}
		}
		else
		{
			ins -= Arr[lo];

			lo++;

			if (lo > hi)
			{
				hi = lo;
				ins = Arr[hi];
			}

			Ans = max(Ans, min(ins, total - ins));
		}
	}

	cout << Ans << '\n';
}