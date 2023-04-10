#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

int N, total;

vector<pii> V;

vector<pii> last; // x로 종료 지점, y로 시작 지점을 담는 벡터.

bool cmp(pii a, pii b)
{
	if (a.y == b.y)
		return a.x > b.x; // 종료 지점이 같다면 시작 지점은 내림차순 정렬한다. 그래야 내가 설계한 내용을 따라 코드가 동작된다. 부등호 방향 바꾸면 큰일난다.
	return a.y < b.y; // 큰 뼈대는 종료 지점을 기준으로 오름차순 정렬. 1931 (회의실 배정) 문제와 나름 같게 생각하면 된다.
}

int main()
{
	cin >> N;

	for (int i = 0, a, b, c, d; i < N; i++)
	{
		cin >> a >> b >> c >> d;

		int L = 100 * a + b, R = 100 * c + d;

		if (L <= 228)
			L = 301;
		if (R >= 1201)
			R = 1201; // 필요없는 날짜 (1/1 ~ 2/28), (12/1 ~ 12/31)을 제거.

		V.push_back({ L, R });
	}

	sort(V.begin(), V.end(), cmp); // 요구된 방식대로 정렬

	for (int i = 0; i < N; i++)
	{
		int Idx = (int)(lower_bound(last.begin(), last.end(), make_pair(V[i].x, -987654321)) - last.begin());

		int S = (int)last.size() - 1;

		while (!last.empty() && S > Idx)
		{
			last.pop_back();
			S--;
		} // ex. last 벡터에 순서대로 501 800 1111 2100이라는 종료 지점이 담겨 있고, 현재 보고 있는 시작점(V[i].x)가 799라면 --> lower_bound가 가리키는 위치는 800. Idx = 1, S = 4 - 1 = 3이다. 따라서 스택 빼듯이, 2100 --> 1111 순으로 2번(S - Idx = 2) 빼주면 된다. 

		while (!last.empty() && last.back().y >= V[i].x) // 현재의 시작점이 벡터의 시작점보다 크거나 같을 때도 필요 없는 선분이므로 이에 포함되는 건 모조리 빼주자.
			last.pop_back();
		last.push_back({ V[i].y, V[i].x }); // 이분 탐색을 편안하게 하기 위해 거꾸로 담아줬다.
	}

	for (int i = 0; i < (int)last.size(); i++)
		swap(last[i].x, last[i].y); // 구현의 헷갈림을 방지하기 위해 원래대로 스위칭.

	int fir = -1;

	for (int i = 0; i < (int)last.size(); i++)
	{
		if (fir != -1 && fir < last[i].x) // ex. 1/1 9/1이고, 9/2 12/30이라 치자. 9/1은 지는 날이라서 꽃이 피는 마지노선은 8/31이다. 따라서 이 때는 9/1에 꽃이 안 피는 날이므로 답은 0이다. 꼭 등호를 빼줘야 한다.
		{
			total = -1;
			break;
		}

		if (i == 0)
		{
			if (last[i].x > 301) // 시작 날짜보다 늦다면 0
			{
				total = -1;
				break;
			}
		}
		if (i == (int)last.size() - 1)
		{
			if (last[i].y <= 1130) // 종료 날까보다 빠르다면 0. 입력이 12 01 이상이어야 꽃이 11월 30일까지 피는 거다!!
			{
				total = -1;
				break;
			}
		}

		fir = last[i].y;
	}

	total == -1 ? total = 0 : total = (int)last.size();

	cout << total; // 정답 출력 (예외에 해당하는 건 0, 아니라면 단순 스택의 사이즈)
}
