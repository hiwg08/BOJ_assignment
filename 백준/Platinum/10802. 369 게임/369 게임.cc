#include <bits/stdc++.h>
#define ll long long
#define MOD (ll)(20150523)

using namespace std;

string A, B;

struct info
{
	ll r[3]{ 0 }; // 나머지가 0, 1, 2일 때의 배열
	ll pa = 0; // 3, 6, 9로 구성되었을 때
	ll sub[3]{ 0 }; // 3, 6, 9로 구성 ***되었고,*** 나머지가 0, 1, 2일 때의 배열
	// 그래서 최종 답은 r + pa - sub 이런 방식이다. (포제의 원리 생각하면 됨)
};

ll precomp[100001]{ 0 }; // 10의 제곱수를 미리 전처리 해두자. (dp 처리할 때 pow로 하면 TLE 날 듯)

info DP[100001][10]{ 0 }; // DP[Idx][number] : 현재 Idx 자릿수 만큼 봤고, number + 9 * (Idx - 1) 의 조합으로 이루어질 때 얻을 수 있는 정보들로 정의.
// ex. DP[7][2] : 0 ~ 2999999까지 봤을 때의 정보. DP[3][4] : 0 ~ 499까지 봤을 때의 정보.

// DP[Idx][1] = DP[Idx][1]
// DP[Idx][2] += DP[Idx][1]
// DP[Idx][3] += DP[Idx][2] ......  (number가 올라갈 때마다 number - 1의 dp 정보를 그대로 누적해주자.)

void at_()
{
	precomp[1] = 10;

	for (ll i = 2; i <= 100000; i++)
		precomp[i] = ((precomp[i - 1] % MOD) * 10) % MOD;
}

void add_mod(ll& ret, ll params)
{
	ret += params;
	ret %= MOD;
}

void sub_mod(ll& ret, ll params)
{
	ret = (ret - params + MOD) % MOD;
}

ll chtoi(char c)
{
	return (ll)(c - '0');
}

void init()
{
	DP[1][0].r[0] = 1; // 0도 3으로 나눈 나머지가 0이므로 1로 초기화 해주자. (어차피 한 자릿수는 해당 dp 정보를 사용하지 않기에 상관 x)

	for (ll i = 1; i <= 9; i++) // 한 자릿수 (0 ~ 9)일 때를 초기화하자. (실제로 369를 셀 때는 해당 dp 정보를 사용하지 않고 solve() 함수의 if (zari == 1) 분기문에서 처리하는 것이 구현에 지장이 없더라.
	{
		for (ll k = 0; k < 3; k++)
		{
			DP[1][i].r[k] += DP[1][i - 1].r[k];
			DP[1][i].sub[k] += DP[1][i - 1].sub[k];
		}

		DP[1][i].pa += DP[1][i - 1].pa;

		DP[1][i].r[i % 3]++;

		if (i % 3 == 0)
		{
			DP[1][i].pa++;
			DP[1][i].sub[0]++;
		}
	}

	DP[1][0].r[0] = 4;

	for (ll i = 1; i < 3; i++)
		DP[1][0].r[i] = 3;

	DP[1][0].pa = 3;

	DP[1][0].sub[0] = 3;

	for (ll i = 2; i <= 100000; i++)
	{
		for (ll j = 0; j < 3; j++)
		{
			DP[i][0].r[j] = DP[i - 1][0].r[j];
			DP[i][0].sub[j] = DP[i - 1][0].sub[j];
		} // 이전 자릿수의 모든 정보(DP[Idx - 1][0])를 미리 현재 자릿수의 모든 정보란에 담아주자.

		DP[i][0].pa = DP[i - 1][0].pa;

		for (ll j = 1; j <= 9; j++)
		{
			ll remain = j % 3;

			for (ll k = 0; k < 3; k++)
				DP[i][j].r[(k + remain) % 3] = DP[i - 1][0].r[k]; // 나머지에 대한 정보를 담아주자.

			if (remain == 0)
			{
				for (ll k = 0; k < 3; k++)
					DP[i][j].sub[k] = DP[i - 1][0].r[k]; // 현재 3, 6, 9가 완전히 확보가 된 상태이므로 sub의 상태는 r 상태로 갱신하면 된다. (sub의 정의가 3, 6, 9가 있으면서 나머지가 0 ~ 2인 것이니까 ㅇㅇ. 이미 3, 6, 9가 있으면 r의 것만 긁어오면 되는 법)

				DP[i][j].pa = precomp[i - 1]; // 3, 6, 9가 0 ~ 9(10), 0 ~ 99(100), 0 ~ 999(1000)개 있는 셈. 그래서 미리 전처리해둔 10 제곱수로 갱신하자.
			}
			else
			{
				for (ll k = 0; k < 3; k++)
					DP[i][j].sub[(k + remain) % 3] = DP[i - 1][0].sub[k]; // 3, 6, 9가 확보되지 않은 상태이면 97줄 처럼 같은 방식으로 sub를 갱신해주자.
				DP[i][j].pa = DP[i - 1][0].pa; // 현재는 3, 6, 9가 없으므로 이전 것의 3, 6, 9의 정보를 긁어와야 한다.
			}

			for (ll k = 0; k < 3; k++) // 2 <- 1, 3 <- 2, 4 <- 3, ... 이런 식이다. 
			{
				add_mod(DP[i][j].r[k], DP[i][j - 1].r[k]);
				add_mod(DP[i][j].sub[k], DP[i][j - 1].sub[k]);
			}
			add_mod(DP[i][j].pa, DP[i][j - 1].pa);
		}

		for (ll k = 0; k < 3; k++)
		{
			DP[i][0].r[k] = DP[i][9].r[k];
			DP[i][0].sub[k] = DP[i][9].sub[k];
		}

		DP[i][0].pa = DP[i][9].pa;
	}
}

ll solve(string B)
{
	ll nu = 0, total = 0;

	bool flag = false;

	for (ll i = 0; i < (ll)B.length(); i++)
	{
		ll zari = (ll)B.length() - i;

		ll Idx = chtoi(B[i]) - 1;

		if (zari == 1) // 한 자릿수일 때는 따로 처리해야 한다.
		{
			for (ll k = 0; k <= chtoi(B[i]); k++)
			{
				if (flag || (k != 0 && (k % 3) == 0) || ((ll)B.length() > 1 && (nu + k) % 3 == 0)) // 순서대로 이미 3, 6, 9가 있을 때 (당연히 박수쳐야함), 현재 수가 3, 6, 9일 때, 모든 자릿수를 더했을 때 3으로 나누어 떨어질 때 (단, B의 자릿수가 두 자릿수 이상이어야 함. 0 때문에 그렇다.) 
					add_mod(total, 1);
			}
			break;
		}

		if (flag) // 이미 3, 6, 9가 있었으면 뒤의 수들을 싹 다 더해주고 바로 반복문을 빠져나오면 된다. (ex. 123456789에서 123까지 봤을 때 --> ans + 456789 + 1을 더하면 된다.)
		{
			ll comp = 0;

			for (ll j = i; j < (ll)B.length(); j++)
				comp = (comp * 10 + chtoi(B[j])) % MOD;

			add_mod(total, 1); // 1 더하는 거 잊지 말자. (어차피 flag가 true라는 건 이미 B가 두 자릿수 이상이라는 뜻이므로 조건 분기 없이 바로 1을 더해도 상관 없다.)
			add_mod(total, comp);
			break;
		}

		if (chtoi(B[i]) == 1) // 현재 보고 있는 숫자가 1일 때 (ex. 100000 --> 0 ~ 99999를 보기 위해 DP[5][9], 즉 여기서는 DP[zari - 1][9]의 정보를 total에 더해준다.
		{
			ll A = DP[zari - 1][9].r[(3 - nu) % 3];

			if (i == 0)
				sub_mod(A, 1);

			add_mod(A, DP[zari - 1][9].pa);
			sub_mod(A, DP[zari - 1][9].sub[(3 - nu) % 3]);
			add_mod(total, A);
		}
		else if (chtoi(B[i]) > 1) // 그게 아닐 때 (ex. 936498 --> 0 ~ 899999를 보기 위해 DP[6][8], 즉 여기서는 DP[zari][pre - 1 (= Idx)]의 정보를 total에 더해준다.
		{
			ll A = DP[zari][Idx].r[(3 - nu) % 3];

			if (i == 0)
				sub_mod(A, 1);

			add_mod(A, DP[zari][Idx].pa);
			sub_mod(A, DP[zari][Idx].sub[(3 - nu) % 3]);
			add_mod(total, A);
		}

		nu = (nu + chtoi(B[i])) % 3;

		if (chtoi(B[i]) != 0 && chtoi(B[i]) % 3 == 0)
			flag = true;
	}

	// 예를 들어 223456789일 때 --> 0 ~ 199999999 / 200000000 ~ 219999999 / 220000000 ~ 222999999 / 223000000 ~ 223999999 / ..... 이런 식이다. 

	return total;
}

int main()
{
	at_();

	init();

	cin >> A >> B;

	ll ans = solve(B);

	sub_mod(ans, solve(A));

	ll nu = 0;

	for (ll i = 0; i < (ll)A.length(); i++)
	{
		nu += chtoi(A[i]);

		if (chtoi(A[i]) != 0 && chtoi(A[i]) % 3 == 0)
		{
			nu = -1;
			break;
		}
	}

	if (nu == -1 || (nu % 3) == 0)
		add_mod(ans, 1); // A 본인이 369 수라면 1 더해준다.

	cout << ans;
}
