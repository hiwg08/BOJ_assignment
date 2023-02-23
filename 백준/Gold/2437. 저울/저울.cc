#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[1001]{ 0 }, Ans;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	for (int i = 0; i < N; i++)
	{
		if (Arr[i] - Ans > 1)
			break;
		Ans += Arr[i];
	}

	cout << Ans + 1 << '\n';
}