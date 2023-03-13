#include <iostream>
#include <string>

using namespace std;

string Input;
int sum;

int main()
{
	string temp = "";
	cin >> Input;
	bool chk = false;
	for (unsigned int i = 0; i < Input.length(); i++)
	{
		if (Input[i] >= '0' && Input[i] <= '9')
			temp += Input[i];
		if (Input[i] == '-' || Input[i] == '+' || i == (Input.length() - 1))
		{
			if (!chk)
				sum += stoi(temp);
			else
				sum -= stoi(temp);
			if (Input[i] == '-')
				chk = true;
			temp = "";
		}
	}
	cout << sum << '\n';
}