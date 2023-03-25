#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int result;

	if (a > 0 && b > 0)
		result = 1;

	else if (a < 0 && b > 0)
		result = 2;
	
	else if (a < 0 && b < 0)
		result = 3;
	
	else if (a > 0 && b < 0)
		result = 4;

	cout<<result<<"\n";
	
	return 0;
}