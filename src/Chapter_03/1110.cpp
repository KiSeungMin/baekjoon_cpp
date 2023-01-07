#include<iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int a, b;
	int cnt{ 1 };
	a = num / 10;
	b = num % 10;
	int x = a;
	int y = b;
	int sum = (x + y) % 10;
	x = y;
	y = sum;
	while ((a != x) || (b != y) )
	{
		sum = (x + y)%10;
		x = y;
		y = sum;
		cnt++;
	}
	cout << cnt;
	return 0;
}