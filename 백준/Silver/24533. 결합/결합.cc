#include <iostream>
#define ll long long

using namespace std;

ll n, sum = 0;

int main()
{
	cin >> n;

	ll L = 0, R = 0;

	for (ll i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;

		sum += (L * b) + (R * a);

		L += a;
		R += b;
	}

	cout << sum;
}