#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
#define o (ll)1

using namespace std;

ll N;

ll mini = LLONG_MAX;

vector<string> S;

pll DP[12][1 << 12]; // DP[last][bits] : 가장 최근에 쓰인 문자열이 last 인덱스 쪽의 문자열이며, 현재까지 쓰인 문자열의 개수(bits)일 떄, 만들 수 있는 문자열의 길이의 최솟값으로 정의
                     // optimal substructure를 만족한다. (증명 완료)

pair<ll, string> comp(string bef, string pre)
{
	string results = "";

	ll maxi = 0, chk = 0;

	for (ll i = (ll)bef.length() - 1; i >= 0; i--)
	{
		ll precomp = (ll)bef.length() - i, cnt = 0;

		for (ll j = i, k = 0; j < (ll)bef.length(); j++, k++)
		{
			if (bef[j] == pre[k])
				cnt++;
		}

		if (precomp == cnt)
			maxi = max(maxi, cnt);

		chk++;

		if (chk == (ll)pre.length())
			break;
	}

	for (ll q = maxi; q < (ll)pre.length(); q++)
		results += pre[q];

	return { maxi, results };
}

pll solve(ll last, ll bits)
{
	if ((ll)__builtin_popcount(bits) == N)
		return { 0, 0 };

	pll& ret = DP[last][bits];

	if (ret.x != -1)
		return ret;

	ret = { LLONG_MAX, 0 };

	string tmp = "";

	for (ll i = 0; i < N; i++)
	{
		if (i == last || bits & (o << i))
			continue;

		pair<ll, string> mid = comp(S[last], S[i]); 

		pll T1 = solve(i, bits | (o << i));

		if (ret.x > (ll)S[i].length() - mid.x + T1.x)
		{
			ret.x = (ll)S[i].length() - mid.x + T1.x;
			ret.y = i;
			tmp = mid.y;
		}
		else if (ret.x == (ll)S[i].length() - mid.x + T1.x)
		{
			if (tmp > mid.y)
			{
				tmp = mid.y;
				ret.y = i;
			}
		}
	}

	return ret;
}

void reconstruct(ll pre, ll bits, ll last)
{
	if (last == -1)
		cout << S[pre];

	if ((ll)__builtin_popcount(bits) == N)
		return;

	pll T1 = solve(pre, bits);

	pair<ll, string> roop = comp(S[pre], S[T1.y]);

	for (ll i = roop.x; i < (ll)S[T1.y].length(); i++)
		cout << S[T1.y][i];

	reconstruct(T1.y, bits | (o << T1.y), pre);
}

void init()
{
	for (ll i = 0; i < 12; i++)
	{
		for (ll j = 0; j < (o << 12); j++)
			DP[i][j] = { -1, -1 };
	}
}

bool cmp(string a, string b)
{
	return (ll)a.length() < (ll)b.length();
}

void pruning()
{
	vector<string> tmp;

	sort(S.begin(), S.end(), cmp);

	for (ll i = 0; i < (ll)S.size(); i++)
	{
		bool chk = true;

		for (ll j = i + 1; j < (ll)S.size(); j++)
		{
			if (S[j].find(S[i]) != string::npos)
			{
				chk = false;
				break;
			}
		}

		if (chk)
			tmp.push_back(S[i]);
	}

	S = tmp;

	N = (ll)S.size();
}

int main()
{
	cin >> N; S.resize(N);

	for (ll i = 0; i < N; i++)
		cin >> S[i];

	pruning();

	string tmp = "";

	ll Idx = 0;

	for (ll i = 0; i < N; i++)
	{
		init();

		pll T = solve(i, o << i);

		if (mini > T.x + (ll)S[i].length())
		{
			mini = T.x + (ll)S[i].length();
			tmp = S[i];
			Idx = i;
		}
		else if (mini == T.x + (ll)S[i].length())
		{
			if (tmp > S[i])
			{
				tmp = S[i];
				Idx = i;
			}
		}
	}

	init();

	reconstruct(Idx, o << Idx, -1);
}