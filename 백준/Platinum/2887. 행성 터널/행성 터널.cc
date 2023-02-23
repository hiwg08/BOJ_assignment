#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tiii tuple<int, int, int>
#define pii pair<int, int>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()

using namespace std;

int N, Parent[100001]{ 0 };

vector<pii> Co[3];

vector<tiii> V;

long long Ans;

bool cmp(tiii T1, tiii T2)
{
	return get<2>(T1) < get<2>(T2);
}

int GetParent(int Idx)
{
	if (Parent[Idx] == 0 || Parent[Idx] == Idx)
		return Parent[Idx] = Idx;
	return Parent[Idx] = GetParent(Parent[Idx]);
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		Co[0].push_back({ a, i });
		Co[1].push_back({ b, i });
		Co[2].push_back({ c, i });
	}

	sort(all(Co[0])); sort(all(Co[1])); sort(all(Co[2]));

	for (int i = 0; i < N; i++)
	{
		if (i != 0)
		{
			V.push_back({ Co[0][i].s, Co[0][i - 1].s, abs(Co[0][i].f - Co[0][i - 1].f)});
			V.push_back({ Co[1][i].s, Co[1][i - 1].s, abs(Co[1][i].f - Co[1][i - 1].f) });
			V.push_back({ Co[2][i].s, Co[2][i - 1].s, abs(Co[2][i].f - Co[2][i - 1].f) });
		}
	}

	sort(V.begin(), V.end(), cmp);

	for (auto e : V)
	{
		int P1 = GetParent(get<0>(e)), P2 = GetParent(get<1>(e));

		if (P1 != P2)
		{
			P1 < P2 ? Parent[P2] = P1 : Parent[P1] = P2;
			Ans += get<2>(e);
		}
	}

	cout << Ans << '\n';
}	