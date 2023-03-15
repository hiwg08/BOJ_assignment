#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using PP = pair<int, int>;

vector<PP> arr_r;

int N, I1, I2, CNT;

int MAX = -1;

bool compare(PP a, PP b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	cin >> N;
	while (N--)
	{
		cin >> I1 >> I2;
		arr_r.push_back({ I1, I2 });
	}

	sort(arr_r.begin(), arr_r.end(), compare);

	for (PP e : arr_r)
	{
		if (e.first >= MAX)
		{
			MAX = e.second;
			CNT++;
		}
	}

	cout << CNT << '\n';
}