#include <bits/stdc++.h>
#define ll long long
#define pls pair<ll, string>
#define all(x) x.begin(), x.end()
#define x first
#define y second

using namespace std;

ll N, K, longest_L = LLONG_MIN;

string longest_S = "", total = "";

string pre_sum[36];

string expos_36[51];

vector<pls> V;

vector<string> coll;

bool change_z[36]{ 0 };

ll cTolo(char a)
{
	return a >= 'A' ? (ll)(a - 55) : (ll)(a - 48);
}

char loToc(ll a)
{
	return a >= 10 ? (char)(a - 10 + 'A') : (char)(a + '0');
}

void change_str(string& params, string t)
{
	string tmp = "";

	for (ll i = 0; i < (ll)t.length() - (ll)params.length(); i++)
		tmp += '0';

	tmp += params, params = tmp;
}

void solve_add(string& A, string B)
{
	string Ans = "";

	(ll)A.length() < (ll)B.length() ? change_str(A, B) : change_str(B, A);

	int carry = 0;

	for (ll i = (ll)A.length() - 1; i >= 0; i--)
	{
		ll pre = cTolo(A[i]) + cTolo(B[i]);

		Ans += to_string((carry + pre) % 10);

		carry = (carry + pre) / 10;
	}

	if (carry == 1) Ans += '1';

	reverse(all(Ans));

	A = Ans;
}

string solve_mul(string fir, string sec)
{
	string Ans = "0";

	vector<string> V;

	ll carry = 1;

	for (ll j = (ll)fir.length() - 1; j >= 0; j--)
	{
		string tmp = "0";

		for (ll k = 0; k < cTolo(fir[j]) * carry; k++)
			solve_add(tmp, sec);

		carry *= 10;

		V.push_back(tmp);
	}

	for (auto& e : V)
		solve_add(Ans, e);

	return Ans;
}

bool cmp(pls a, pls b)
{
	if ((ll)a.y.length() == (ll)b.y.length())
		return a.y > b.y;
	return (ll)a.y.length() > (ll)b.y.length();
}

void init()
{
	expos_36[0] = "1";

	for (ll i = 1; i <= 50; i++)
		expos_36[i] = solve_mul("36", expos_36[i - 1]);

	for (ll i = 0; i < 36; i++)
		pre_sum[i] = "0";
}

int main()
{
	cin >> N;

	init();

	for (ll i = 0; i < N; i++)
	{
		string A; cin >> A;

		coll.push_back(A);

		longest_L = max((ll)A.length(), longest_L);

		for (ll j = (ll)A.length() - 1; j >= 0; j--)
			solve_add(pre_sum[cTolo(A[j])], solve_mul(to_string(35 - cTolo(A[j])), expos_36[(ll)A.length() - 1 - j]));
	}

	for (ll i = 0; i < longest_L; i++)
		longest_S += '0';

	cin >> K;

	for (ll i = 0; i < 36; i++)
		V.push_back({ i, pre_sum[i] });

	sort(all(V), cmp);

	for (ll i = 0; i < (ll)V.size(); i++)
	{
		if (--K == -1) break;

		change_z[V[i].x] = true;
	}

	for (ll i = 0; i < (ll)coll.size(); i++)
	{
		for (auto& e : coll[i])
		{
			if (change_z[cTolo(e)])
				e = 'Z';
		}
	}

	for (auto& e : coll) change_str(e, longest_S);

	ll carry = 0;

	for (ll i = longest_L - 1; i >= 0; i--)
	{
		ll Sum = 0;
		for (ll j = 0; j < (ll)coll.size(); j++)
			Sum += cTolo(coll[j][i]);

		total += loToc((carry + Sum) % 36);

		carry = (carry + Sum) / 36;
	}

	while (carry != 0)
	{
		total += loToc(carry % 36);
		carry /= 36;
	}

	reverse(all(total));

	cout << total << '\n';
}