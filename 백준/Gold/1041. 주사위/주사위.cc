#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, one, two, three = 4;

ll min_1 = LLONG_MAX, min_2 = LLONG_MAX, min_3 = LLONG_MAX;

ll dice[6]{ 0 };

string sight_one[]{ "A", "B", "C", "D", "E", "F" };

string sight_two[]{ "AC", "AB", "AD", "AE", "FC", "FB", "FD", "FE", "CB", "BD", "DE", "EC"};

string sight_three[]{ "ACB", "ABD", "AED", "AEC", "FCB", "FBD", "FED", "FEC" };

ll ctoll(char c)
{
	return (ll)(c - 65);
}

void find_min(string* arr, ll loop, ll& ret)
{
	for (ll i = 0; i < loop; i++)
	{
		ll T1 = 0;

		for (auto e : arr[i])
			T1 += dice[ctoll(e)];

		ret = min(ret, T1);
	}
}

int main()
{
	cin >> N;

	ll user = LLONG_MIN, sum = 0;

	for (ll i = 0; i < 6; i++)
	{
		cin >> dice[i];
		user = max(user, dice[i]);
		sum += dice[i];
	}

	if (N == 1)
	{
		cout << sum - user << '\n';
		exit(0);
	}

	one = (N - 2) * (N - 1) * 4 + (ll)pow(N - 2, 2);

	two = 8 * (N - 2) + 4;

	find_min(sight_one, 6, min_1);
	find_min(sight_two, 12, min_2);
	find_min(sight_three, 8, min_3);

	cout << one * min_1 + two * min_2 + three * min_3 << '\n';
}
