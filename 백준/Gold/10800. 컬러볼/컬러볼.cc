#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, Sum_Huge[200001]{ 0 }, Sum_Color[200001]{ 0 }, Ans[200001]{ 0 };

vector<pair<pii, int>> Huge_V, Color_V;

vector<int> U[200001];

bool H_cmp(pair<pii, int> a, pair<pii, int> b)
{
	if (a.x.y == b.x.y)
		return a.x.x < b.x.x;
	return a.x.y < b.x.y;
}
bool C_cmp(pair<pii, int> a, pair<pii, int> b)
{
	if (a.x.x == b.x.x)
		return a.x.y < b.x.y;
	return a.x.x < b.x.x;
}

void Input()
{
	cin >> N;

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		Huge_V.push_back({ {a, b}, i });
		Color_V.push_back({ {a, b}, i });
	}

	sort(Huge_V.begin(), Huge_V.end(), H_cmp);
	sort(Color_V.begin(), Color_V.end(), C_cmp);

	int Chk = 0;

	for (int i = 1; i <= N; i++)
	{
		Sum_Huge[i] = Sum_Huge[i - 1] + Huge_V[i - 1].x.y;

		Sum_Color[i] = Sum_Color[i - 1] + Color_V[i - 1].x.y;

		U[Color_V[i - 1].x.x].push_back(Color_V[i - 1].x.y);
	}
}

int main()
{
	fastio;

	Input();

	for (int i = 0; i < N; i++)
	{
		int L = (int)(lower_bound(Huge_V.begin(), Huge_V.end(), pair<pii, int>({ {0, Huge_V[i].x.y}, 0}), H_cmp) - Huge_V.begin());
		int Mid = (int)(lower_bound(Color_V.begin(), Color_V.end(), pair<pii, int>({ {Huge_V[i].x.x, 0}, 0 })) - Color_V.begin());
		int R = (int)(lower_bound(U[Huge_V[i].x.x].begin(), U[Huge_V[i].x.x].end(), Huge_V[i].x.y) - U[Huge_V[i].x.x].begin()) + Mid;

		Ans[Huge_V[i].y] = Sum_Huge[L] - (Sum_Color[R] - Sum_Color[Mid]);
	}

	for (int i = 0; i < N; i++)
		cout << Ans[i] << '\n';
}