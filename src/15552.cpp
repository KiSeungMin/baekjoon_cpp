#include<iostream>
#define sync_with_stdio(false);
using namespace std;

int main()
{
	int a;
	cin.tie(NULL);
	cin >> a;
	for (int i{ 0 }; i < a; i++)
	{
		int b, c;
		cin >> b >> c;
		cout << b + c << "\n";
	}
	return 0;
}