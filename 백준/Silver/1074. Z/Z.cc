#include <bits/stdc++.h>


using namespace std;

int N, R, C;

void solve(int n, int r, int c, int num)
{
	if (n == 1)
	{
		cout << num + (2 * r + c);
		return;
	}

	int real = (1 << (n - 1));

	int a = r / real, b = c / real;

	solve(n - 1, r - (a * real), c - (b * real), num + ((2 * a + b) * real * real));

	return;
}

int main()
{
	cin >> N >> R >> C;

	solve(N, R, C, 0);
}