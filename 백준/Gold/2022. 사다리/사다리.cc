#include <bits/stdc++.h>

using namespace std;

double x, y, c;

double calc(double mid)
{
	return ((sqrt(x * x - mid * mid) * sqrt(y * y - mid * mid)) / (sqrt(x * x - mid * mid) + sqrt(y * y - mid * mid)));
}

int main()
{
	cin >> x >> y >> c;

	double lo = -0.001, hi = x > y ? x + 0.001 : y + 0.001;

	while (lo + 0.001 < hi)
	{
		double mid = (lo + hi) / (double)2;

		calc(mid) >= c ? lo = mid : hi = mid;
	}

	cout.precision(3);

	cout << fixed << lo << '\n';
}