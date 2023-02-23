#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, H, D[100001]{ 0 }, U[100001]{ 0 }, Interval_Cnt, MIN = INT_MAX;

int main()
{
	fastio;

	cin >> N >> H;

	for (int i = 0; i < N / 2; i++)
		cin >> D[i] >> U[i];

	sort(D, D + (N / 2));
	sort(U, U + (N / 2));

	for (int i = 1; i <= H; i++)
	{
		int Break_D = (N / 2) - (int)(lower_bound(D, D + (N / 2), i) - D);
		int Break_U = (N / 2) - (int)(lower_bound(U, U + (N / 2), (H - i + 1)) - U);

		if (MIN > Break_D + Break_U)
		{
			MIN = Break_D + Break_U;
			Interval_Cnt = 0;
			Interval_Cnt++;
		}
		else if (MIN == Break_D + Break_U)
			Interval_Cnt++;
	}

	cout << MIN << " " << Interval_Cnt << '\n';
}