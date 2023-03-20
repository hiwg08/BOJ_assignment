#include <bits/stdc++.h>

using namespace std;

string A, B;

int a_cnt, b_cnt;

int main()
{
	cin >> A >> B;

	for (auto e : A)
	{
		if (e == '1') a_cnt++;
	}
	for (auto e : B)
	{
		if (e == '1') b_cnt++;
	}

	if (a_cnt % 2 == 0) // 짝수일 때
		b_cnt <= a_cnt ? cout << "VICTORY" << '\n' : cout << "DEFEAT" << '\n';

	else
		b_cnt <= a_cnt + 1 ? cout << "VICTORY" << '\n' : cout << "DEFEAT" << '\n';
}