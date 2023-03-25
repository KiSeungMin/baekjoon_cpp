#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <char> vec;
	char a;
	int cnt{ 1 };
	for (int i = 0; i < 1000000; i++)
	{
		a = getchar();
		if (a == '\n')
		{
			break;
		}
		vec.push_back(a);
	}
	if (vec.size() == 0)
		cout << 0;
	if (vec.size() > 0) {
		for (int i = 0; i < vec.size(); i++)
		{
			if ((i != 0) && (vec[i] == ' '))
			{
				cnt += 1;
			}
		}

		if (vec[vec.size() - 1] == ' ')
		{
			cnt -= 1;
		}
	}

	if (vec[0] == ' ' && vec.size() == 1)
		cnt = 0;
	cout << cnt;
	return 0;
}