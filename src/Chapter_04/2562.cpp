#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main()
{
	cin.tie(NULL);
	int a{9};
	vector<int>arr;
	for (int i{ 0 }; i < a; i++)
	{
		int b;
		cin >> b;
		arr.push_back(b);
	}
	int max{ 0 };
	for (size_t i{ 0 }; i < arr.size(); i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	int k{0};
	for (size_t i{ 0 }; i < arr.size(); i++)
	{
		if (arr[i] == max)
		{
			k = i;
		}
	}
	cout << max << "\n";
	cout << k+1;
	return 0;
}