#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

ll T, N, W, total = LLONG_MAX;

ll Arr_U[10001]{ 0 }, Arr_D[10001]{ 0 };

ll DP[10001][4]{ 0 }; // 현재 Idx에서, state가 0 ~ 3일 때, 이을 수 있는 요원의 최솟값
// state : 0 --> 위, 아래 단독으로만 쓰일 때
// state : 1 --> 위, 아래 모두 사용 중일 때 (이미 다른 곳과 연결되어있는 경우)
// state : 2 --> 위만 사용 중일 때. 아래는 사용 X
// state : 3 --> 아래만 사용 중일 때. 위는 사용 X

ll store_u_l, store_d_l; // 가장 왼쪽의 위, 아래 값을 저장해놓는 변수. 

ll solve(ll state) // 여기서의 state는 dp 배열에서의 state와는 다르다. (다음에는 헷갈리지 않도록 의미를 동일하게 좀 써놓자 ㅡㅡ)
// state : 0 --> 위의 숫자들이 지워졌을 때
// state : 1 --> 아래의 숫자들이 지워졌을 때
// state : 2 --> 위, 아래 숫자들 모두 지워졌을 때
// state : 3 --> 어떠한 숫자도 지워지지 않았을 때
{
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < 4; j++)
			DP[i][j] = 99999;
	}

	for (ll i = 0; i < N; i++)
	{
		if (i == 0)
		{
			if (state == 0 || state == 1)  // 위 또는 아래 숫자가 지워졌을는 위 또는 아래 숫자 단 '하나'만 남았기 때문에 DP[i][0] 값이 1이다.
				DP[i][0] = 1;

			if (state == 2) // 모든 숫자가 지워졌을 때는 아무런 숫자가 남지 않았기 때문에 DP[i][0] 값이 0이다.
				DP[i][0] = 0;

			if (state == 3) // 이건 본래 했던 대로 진행.
			{
				DP[i][0] = 2;

				if (Arr_U[i] + Arr_D[i] <= W)
					DP[i][1] = 1;
			}
		}
		else if (i < N - 1 || (i == N - 1 && state == 3))
		{
			DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 2;

			if (Arr_U[i] + Arr_U[i - 1] <= W && Arr_D[i] + Arr_D[i - 1] <= W)
				DP[i][1] = DP[i - 1][0];

			if (Arr_U[i] + Arr_D[i] <= W)
				DP[i][1] = min(DP[i][1], min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1);

			if (Arr_U[i] + Arr_U[i - 1] <= W)
				DP[i][2] = min(DP[i - 1][0], DP[i - 1][3]) + 1;

			if (Arr_D[i] + Arr_D[i - 1] <= W)
				DP[i][3] = min(DP[i - 1][0], DP[i - 1][2]) + 1;
		}
		else if (i == N - 1)
		{
			if (state == 0) // 위 숫자만 지워진 거면 0 (둘다 사용 X)과 3 (아래만 사용 중)만 필요하다.
			{
				DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1;

				if (Arr_D[i] + Arr_D[i - 1] <= W)
					DP[i][3] = min(DP[i - 1][0], DP[i - 1][2]); // 여기는 1을 안 더해주는 게 핵심 되겠다. (위 숫자가 쓰이지 않기 때문에 1는 반드시 빼야함)
			}
			if (state == 1)  // 아래 숫자만 지워진 거면 0 (둘다 사용 X)과 2 (위만 사용 중)만 필요하다.
			{
				DP[i][0] = min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }) + 1;

				if (Arr_U[i] + Arr_U[i - 1] <= W)
					DP[i][2] = min(DP[i - 1][0], DP[i - 1][3]); // 여기는 1을 안 더해주는 게 핵심 되겠다. (아래 숫자가 쓰이지 않기 때문에 1는 반드시 빼야함)
			}
			if (state == 2)
				return min({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }); // 두 숫자가 모두 쓰이지 않으면 바로 이전 값을 리턴해준다.
		}
	}

	return min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2], DP[N - 1][3] });
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		total = LLONG_MAX;

		cin >> N >> W;

		for (ll i = 0; i < N; i++)
			cin >> Arr_U[i];

		for (ll i = 0; i < N; i++)
			cin >> Arr_D[i];

		store_u_l = Arr_U[0], store_d_l = Arr_D[0];

		total = min(total, solve(3));

		if (Arr_U[0] + Arr_U[N - 1] <= W)
		{
			Arr_U[0] = 99999;
			total = min(total, solve(0) + 1);
			Arr_U[0] = store_u_l;
		}
		if (Arr_D[0] + Arr_D[N - 1] <= W)
		{
			Arr_D[0] = 99999;
			total = min(total, solve(1) + 1);
			Arr_D[0] = store_d_l;
		}
		if (Arr_U[0] + Arr_U[N - 1] <= W && Arr_D[0] + Arr_D[N - 1] <= W)
		{
			Arr_U[0] = 99999;
			Arr_D[0] = 99999;
			total = min(total, solve(2) + 2);
		}
		// 원형이라서 반드시 선형으로 해석하여 풀어야 한다. 따라서 이렇게 많은 조건분기가 나뉘어진 것.

		cout << total << '\n';
	}
}
