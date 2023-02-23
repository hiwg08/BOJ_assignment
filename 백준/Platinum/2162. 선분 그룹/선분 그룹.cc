#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second
#define MAX 3000

using namespace std;

typedef struct line
{
	pll a, b;
	line(pll _T1, pll _T2)
	{
		a = _T1;
		b = _T2;
	}
} line;

vector<line> V;

ll N, Group_Cnt, Ans = INT_MIN;

ll Parent[MAX + 1]{ 0 }, Node[MAX + 1]{ 0 };

bool Vis[MAX + 1]{ 0 };

ll CCW(pll a, pll b, pll c)
{
	return ((b.f - a.f) * (c.s - a.s)) + ((a.s - b.s) * (c.f - a.f));
}

bool match_line(line L, line R)
{
	if ((CCW(L.a, L.b, R.a) * CCW(L.a, L.b, R.b) <= 0) &&
		(CCW(R.a, R.b, L.a) * CCW(R.a, R.b, L.b) <= 0))
	{
		if ((CCW(L.a, L.b, R.a) * CCW(L.a, L.b, R.b) == 0) &&
			(CCW(R.a, R.b, L.a) * CCW(R.a, R.b, L.b) == 0))
		{
			pll L_F = L.a, L_S = L.b, R_F = R.a, R_S = R.b;
			if (L_F > L_S)
				swap(L_F, L_S);
			if (R_F > R_S)
				swap(R_F, R_S);

			if (L_S < R_F || R_S < L_F)
				return false;
			return true;
		}
		return true;
	}
	return false;
}

ll GetParent(ll Idx)
{
	if (Parent[Idx] == Idx)
		return Parent[Idx] = Idx;
	return Parent[Idx] = GetParent(Parent[Idx]);
}

void Init()
{
	for (ll i = 1; i <= MAX; i++)
	{
		Parent[i] = i;
		Node[i] = 1;
	}
}

int main()
{
	fastio;

	cin >> N;

	V.push_back(line({ -1, -1 }, { -1, -1 }));

	Init();

	for (ll i = 0, a, b, c, d; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		V.push_back(line({a, b}, {c, d}));
	}

	for (ll i = 1; i <= N; i++)
	{
		for (ll j = i + 1; j <= N; j++)
		{
			if (match_line(V[i], V[j]))
			{
				ll P1 = GetParent(i), P2 = GetParent(j);
				if (P1 != P2)
				{
					if (P1 < P2)
					{
						Parent[P2] = P1;
						Node[P1] += Node[P2];
					}
					else
					{
						Parent[P1] = P2;
						Node[P2] += Node[P1];
					}
				}
			}
		}
	}

	for (ll i = 1; i <= N; i++)
		Parent[i] = GetParent(i);

	for (ll i = 1; i <= N; i++)
	{
		if (!Vis[Parent[i]])
		{
			Vis[Parent[i]] = true;
			Group_Cnt++;
			Ans = max(Ans, Node[Parent[i]]);
		}
	}

	cout << Group_Cnt << '\n' << Ans << '\n';
}