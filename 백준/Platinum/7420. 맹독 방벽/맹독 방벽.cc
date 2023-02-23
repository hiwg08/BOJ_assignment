#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI 3.1415926535

using namespace std;

typedef struct _point
{
	int x, y, rel_x, rel_y;
	_point(int _x = 0, int _y = 0, int _rel_x = 0, int _rel_y = 0)
	{
		x = _x, y = _y, rel_x = _rel_x, rel_y = _rel_y;
	}
} point;

int N, L;

long double Ans;

point P[1001];

bool cmp(point P1, point P2)
{
	if (P1.rel_x * P2.rel_y != P1.rel_y * P2.rel_x)
		return P1.rel_x * P2.rel_y > P1.rel_y * P2.rel_x;

	if (P1.y == P2.y)
		return P1.x < P2.x;
	return P1.y < P2.y;
}

int CCW(int a1, int a2, int b1, int b2, int c1, int c2)
{
	return ((b1 - a1) * (c2 - a2)) + ((a2 - b2) * (c1 - a1));
}

void make_convex_hull(vector<point>& S)
{
	S.push_back(P[0]); S.push_back(P[1]);

	for (int i = 2; i <= N; i++)
	{
		while ((int)S.size() > 2 && CCW(S[(int)S.size() - 2].x, S[(int)S.size() - 2].y, S[(int)S.size() - 1].x, S[(int)S.size() - 1].y, P[i].x, P[i].y) < 0)
			S.pop_back();
		S.push_back(P[i]);
	}
}

int main()
{
	fastio;

	cin >> N >> L;

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b; P[i].x = a, P[i].y = b;
	}

	sort(P, P + N, cmp);

	for (int i = 1; i < N; i++)
	{
		P[i].rel_x = P[i].x - P[0].x;
		P[i].rel_y = P[i].y - P[0].y;
	}

	sort(P + 1, P + N, cmp);

	P[N].x = P[0].x, P[N].y = P[0].y;

	vector<point> S;

	make_convex_hull(S);

	for (int i = 1; i < (int)S.size(); i++)
		Ans += (long double)sqrt(((S[i].x - S[i - 1].x) * (S[i].x - S[i - 1].x)) + ((S[i].y - S[i - 1].y) * (S[i].y - S[i - 1].y)));

	Ans += 2 * L * PI;

	cout << (long long)floor(Ans + 0.5) << '\n';
}