#include <bits/stdc++.h>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll unsigned long long
#define pll pair<ll, ll>
#define x first
#define y second

using namespace std;

const ll MOD = (ll)(pow(2, 64));

ll M, N, remain, past_c = 0, pre_c, Ans, Sum;

unordered_map<ll, ll> UM;

vector<pll> V;

void mul_mod(ll& params, ll cons)
{
	params *= cons;
	params %= MOD;
}

void add_mod(ll& params, ll cons)
{
	params += cons;
	params %= MOD;
}

int main()
{
	fastio;

	cin >> M >> N;

	for (ll i = 0, a; i < N; i++)
	{ 
		cin >> a;
		UM[a]++;
		add_mod(Sum, a);
	}

	remain = N;

	for (auto& e : UM)
		V.push_back({ e.x, e.y });

	sort(V.begin(), V.end());

	for (ll i = 0; i < (ll)V.size(); i++)
	{
		if (i == 0) pre_c += V[i].x * remain;
		else
		{
			past_c = pre_c;
			pre_c += (V[i].x - V[i - 1].x) * remain;
		}

		if (pre_c >= Sum - M)
		{
			for (ll j = 0; j < i; j++)
			{
				for (ll k = 0; k < V[j].y; k++)
					add_mod(Ans, (V[j].x * V[j].x));
			}

			ll standard = 0;
		
			i == 0 ? standard = 0 : standard = V[i - 1].x;

			ll diff = Sum - M - past_c;

			ll quo = diff / remain, r = diff % remain;

			ll T1 = 1, T2 = 1;

			mul_mod(T1, standard + quo); mul_mod(T1, standard + quo); mul_mod(T1, remain - r);

			mul_mod(T2, standard + quo + 1); mul_mod(T2, standard + quo + 1); mul_mod(T2, r);

			add_mod(T1, T2); add_mod(Ans, T1);

			break;
		}

		remain -= V[i].y;
	}

	cout << Ans << '\n';
}