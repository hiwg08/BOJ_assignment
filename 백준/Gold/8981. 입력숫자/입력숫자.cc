#include <bits/stdc++.h>

using namespace std;

int N, From = 0, Arr[31]{ 0 }, Ans[31]{ 0 };

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++) cin >> Arr[i];

	Ans[0] = Arr[0];

	for (int i = 1; i < N; i++)
	{
		From = (From + Arr[i - 1]) % N;

		while (Ans[From] != 0) From = (From + 1) % N;

		Ans[From] = Arr[i];
	}

	cout << N << '\n';
	
	for (int i = 0; i < N; i++) cout << Ans[i] << " ";

	cout << '\n';
}