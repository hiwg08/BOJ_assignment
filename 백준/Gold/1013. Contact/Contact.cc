#include <bits/stdc++.h>
#include <regex>

using namespace std;

int T;

string S;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> S;

		regex comp("(100+1+|01)+");

		bool ans = regex_match(S, comp);

		ans ? cout << "YES" : cout << "NO";

		cout << '\n';
	}
}