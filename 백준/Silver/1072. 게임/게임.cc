#include <iostream>
#define ll long long

using namespace std;

double X, Y;

int main()
{
	cin >> X >> Y;

	double mid = (double)((100 * Y) / X);

	ll pre_pro = (ll)(mid);

	if (pre_pro == 99 || pre_pro == 100)
		cout << -1;
	else
	{
		pre_pro++;
		double res = (double)(pre_pro * X - 100 * Y) / (100 - pre_pro);

		ll L = (ll)res, R = L + 1;

		double D1 = (double)(100 * (Y + L)) / (double)(X + L), D2 = (double)(100 * (Y + R)) / (double)(X + R);

		ll A1 = (ll)(D1), A2 = (ll)(D2);

		if (A1 >= pre_pro)
			cout << L;
		else if (A2 >= pre_pro)
			cout << R;
		else
			cout << -1;
	}
}