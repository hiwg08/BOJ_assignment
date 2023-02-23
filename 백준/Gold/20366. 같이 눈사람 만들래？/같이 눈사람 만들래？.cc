#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[601]{ 0 }, Ans = INT_MAX;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 3; j < N; j++)
		{
			int standard = Arr[i] + Arr[j];
			int lo = i + 1, hi = j - 1, Sum = Arr[lo] + Arr[hi];

			Ans = min(Ans, abs(standard - Sum));

			while (lo < hi)
			{
				Sum > standard ? hi-- : lo++;

				if (lo < hi)
				{
					Sum = Arr[lo] + Arr[hi];
					Ans = min(Ans, abs(standard - Sum));
				}
			}
		}
	}

	cout << Ans << '\n';
}