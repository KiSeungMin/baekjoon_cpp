#include<iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;

    bool result;

	if (a % 4 == 0 && a % 400 == 0)
		result = true;

	else if (a % 4 == 0 && a % 100 != 0)
		result = true;
	
	else
		result = false;

    cout<<static_cast<int>(result)<<"\n";

	return 0;
}