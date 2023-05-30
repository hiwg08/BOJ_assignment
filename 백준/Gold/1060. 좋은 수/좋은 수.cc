#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll L, N;

deque<ll> V;

struct info
{
	ll num;
	bool chk;
	ll good_num;
	ll cnt;
	ll limi;
	ll interv;

	info(ll _num, bool _chk, ll _good_num, ll _cnt, ll _limi, ll _interv)
		:num(_num), chk(_chk), good_num(_good_num), cnt(_cnt), limi(_limi), interv(_interv)
	{}
};

struct comp
{
	bool operator()(info a, info b)
	{
		if (a.good_num == b.good_num)
			return a.num > b.num;
		return a.good_num > b.good_num;
	}
};

priority_queue<info, vector<info>, comp> PQ;

int main()
{
	cin >> L; V.resize(L);

	for (auto& iv : V)
		cin >> iv;

	cin >> N;

	sort(V.begin(), V.end());

	for (auto e : V)
		PQ.push(info(e, false, 0, 0, 0, 0));

	V.push_front(0);

	for (ll i = 0; i < (ll)V.size() - 1; i++)
	{
		ll L = V[i] + 1, R = V[i + 1] - 1;

		if (L > R)
			continue;

		ll interval = R - L + 1;

		if (interval % 2 == 0) // interval이 짝수일 때
		{
			info a = info(L, true, interval - 1, 1, interval / 2, interval);
			PQ.push(a);
			info b = info(R, false, interval - 1, 1, interval / 2, interval);
			PQ.push(b);
		}
		else // interval이 홀수일 때
		{
			info a = info(L, true, interval - 1, 1, interval / 2 + 1, interval);
			PQ.push(a);

			if (interval > 1)
			{
				info b = info(R, false, interval - 1, 1, interval / 2, interval);
				PQ.push(b);
			}
		}
	}

	while (!PQ.empty())
	{
		info tmp = PQ.top();
		PQ.pop();

		cout << tmp.num << " ";

		if (tmp.cnt < tmp.limi)
		{
			ll new_num = tmp.num;

			if (tmp.chk)
				new_num++;
			else
				new_num--;

			ll new_cnt = tmp.cnt + 1;

			ll new_good_num = tmp.good_num + tmp.interv - 2 * tmp.cnt;

			PQ.push(info(new_num, tmp.chk, new_good_num, new_cnt, tmp.limi, tmp.interv));
		}

		N--;
		if (N == 0)
			break;
	}

	ll Idx = V[(ll)V.size() - 1] + 1;

	while (N > 0)
	{
		cout << Idx++ << " ";
		N--;
	}
}