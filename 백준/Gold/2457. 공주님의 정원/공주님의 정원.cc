#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, total;

vector<pii> V;

vector<pii> last; // x로 종료 지점, y로 시작 지점

bool cmp(pii a, pii b)
{
	if (a.y == b.y)
		return a.x > b.x;
	return a.y < b.y;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0, a, b, c, d; i < N; i++)
	{
		cin >> a >> b >> c >> d;

		int L = 100 * a + b, R = 100 * c + d;

		if (L <= 228)
			L = 301;
		
		if (R >= 1201)
			R = 1201;

		V.push_back({ L, R });
	}

	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		int Idx = (int)(lower_bound(last.begin(), last.end(), make_pair(V[i].x, -987654321)) - last.begin());

		int S = (int)last.size() - 1;

		while (!last.empty() && S > Idx)
		{
			last.pop_back();
			S--;
		}

		while (!last.empty() && last.back().y >= V[i].x) // 현재 보고 있는 좌표
			last.pop_back();
		last.push_back({ V[i].y, V[i].x });
	}

	for (int i = 0; i < (int)last.size(); i++)
		swap(last[i].x, last[i].y);

	int fir = -1;

	for (int i = 0; i < (int)last.size(); i++)
	{
		if (fir != -1 && fir < last[i].x)
		{
			total = -1;
			break;
		}

		if (i == 0)
		{
			if (last[i].x > 301)
			{
				total = -1;
				break;
			}
		}
		if (i == (int)last.size() - 1)
		{
			if (last[i].y <= 1130)
			{
				total = -1;
				break;
			}
		}

		fir = last[i].y;
	}

	total == -1 ? total = 0 : total = (int)last.size();

	cout << total;
}