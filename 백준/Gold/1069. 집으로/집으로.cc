#include <bits/stdc++.h>

using namespace std;

int X, Y, J, T;

double dist;

double total;

double calc(int x, int y)
{
	return (double)(sqrt((double)x * x + (double)y * y));
}

int main()
{
	cin >> X >> Y >> J >> T;

	dist = calc(X, Y);

	total = dist;

	if (J > dist)
	{
		double comp = min(2 * (double)T, (double)T + (double)J - dist);
		total = min(total, comp);
	}
	else if (J == dist)
		total = min(total, (double)T);
	else
	{
		double tmp = J;

		int Idx = 1;

		while (true)
		{
			if (tmp > dist)
			{
				tmp -= (double)J;
				break;	
			}
			tmp += (double)J;
			Idx++;
		}

		double comp = min((double)(T * Idx), (double)(T * (Idx - 1) + (double)abs(tmp - dist)));
		total = min(total, comp);
	}

	cout.precision(9);

	cout << fixed << total << '\n';
}