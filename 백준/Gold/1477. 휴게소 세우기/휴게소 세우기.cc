#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, L, Arr[51]{ 0 }, MAX = INT_MIN;

int Install_Rest(int mid)
{
	int Ans = 0;

	for (int i = 1; i <= N; i++)
		(Arr[i] - Arr[i - 1]) % mid == 0 ? Ans += (Arr[i] - Arr[i - 1]) / mid - 1 : Ans += (Arr[i] - Arr[i - 1]) / mid;

	(L - Arr[N]) % mid == 0 ? Ans += (L - Arr[N]) / mid - 1 : Ans += (L - Arr[N]) / mid;

	return Ans;
}

int Binary_Search() // upper bound 구하는 문제
{
	int lo = 0, hi = MAX;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (Install_Rest(mid) <= M)
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main()
{
	fastio;

	cin >> N >> M >> L;

	for (int i = 1; i <= N; i++)
		cin >> Arr[i];

	sort(Arr + 1, Arr + N + 1);

	for (int i = 1; i <= N; i++)
		MAX = max(MAX, Arr[i] - Arr[i - 1]);
	MAX = max(MAX, L - Arr[N]);

	cout << Binary_Search() << '\n';
}