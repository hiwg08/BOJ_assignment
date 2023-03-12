#include <bits/stdc++.h>

using namespace std;

int N, repair[1001]{ 0 }, origin[1001]{ 0 }, total;

void sol(int last, int& first, int& size, bool flag)
{
	if (size == INT_MAX)
		return;

	total += size;

	if (!flag)
		size = -size;

	for (int k = last; k >= first; k--)
		repair[k] += size;

	size = INT_MAX;

	first = last + 1;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> repair[i];

	for (int i = 0; i < N; i++)
		cin >> origin[i];

	while (1)
	{
		int l_size = INT_MAX, s_size = INT_MAX;

		int first_ptr = 0;

		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			if (repair[i] < origin[i])
			{
				sol(i - 1, first_ptr, l_size, 0);
				s_size = min(s_size, abs(repair[i] - origin[i]));
			}
			else if (repair[i] > origin[i])
			{
				sol(i - 1, first_ptr, s_size, 1);
				l_size = min(l_size, abs(repair[i] - origin[i]));
			}
			else
			{
				cnt++;
				sol(i - 1, first_ptr, l_size, 0);
				sol(i - 1, first_ptr, s_size, 1);
				first_ptr = i + 1;
			}
		}

		sol(N - 1, first_ptr, l_size, 0);
		sol(N - 1, first_ptr, s_size, 1);

		if (cnt == N)
			break;
	}

	cout << total << '\n';
}