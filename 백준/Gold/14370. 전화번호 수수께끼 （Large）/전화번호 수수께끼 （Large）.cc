#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int T;

string S;

multiset<char> ms;

vector<int> ans;

void erase_one(string V)
{
	for (auto& iv : V)
	{
		auto it = ms.lower_bound(iv);
		ms.erase(it);
	}
}

void solve()
{
	for (int i = 0; i < (int)S.length(); i++)
		ms.insert(S[i]);

	while (!ms.empty())
	{
		bool chk = false;

		if (ms.find('W') != ms.end()) // 2이다.
		{
			chk = true;
			ans.pb(2);
			erase_one("TWO");
		}
		else if (ms.find('X') != ms.end()) // 6이다.
		{
			chk = true;
			ans.pb(6);
			erase_one("SIX");
		}
		else if (ms.find('G') != ms.end()) // 8이다.
		{
			chk = true;
			ans.pb(8);
			erase_one("EIGHT");
		}
		else if (ms.find('U') != ms.end()) // 4이다.
		{
			chk = true;
			ans.pb(4);
			erase_one("FOUR");
		}
		else if (ms.find('Z') != ms.end()) // 4이다.
		{
			chk = true;
			ans.pb(0);
			erase_one("ZERO");
		}
		else if (ms.find('V') != ms.end()) // 4이다.
		{
			chk = true;
			if (ms.find('S') != ms.end())
			{
				erase_one("SEVEN");
				ans.pb(7);
			}
			else
			{
				ans.pb(5);
				erase_one("FIVE");
			}
		}

		if (!chk)
			break;
	}

	while (!ms.empty())
	{
		bool chk = false;

		if (ms.find('I') != ms.end()) // 2이다.
		{
			chk = true;
			ans.pb(9);
			erase_one("NINE");
		}
		else if (ms.find('O') != ms.end()) // 6이다.
		{
			chk = true;
			ans.pb(1);
			erase_one("ONE");
		}
		else if (ms.find('T') != ms.end()) // 8이다.
		{
			chk = true;
			ans.pb(3);
			erase_one("THREE");
		}
		if (!chk)
			break;
	}
}

int main()
{
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> S;

		ms.clear();

		ans.clear();

		solve();

		sort(ans.begin(), ans.end());

		cout << "Case #" << i << ": ";

		for (auto e : ans)
			cout << e;
		cout << '\n';
	}
}