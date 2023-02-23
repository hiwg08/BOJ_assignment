#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[1000001]{ 0 }, Cnt[1000001]{ 0 }, Ans;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N; i++)
	{
		if (Cnt[Arr[i]] == 0)
		{
			Cnt[Arr[i] - 1]++;
			Ans++;
		}
		else
		{
			Cnt[Arr[i]]--;
			Cnt[Arr[i] - 1]++;
		}
	}

	cout << Ans << '\n';

}