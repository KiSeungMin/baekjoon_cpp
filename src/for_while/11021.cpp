#include<iostream>
#define sync_with_stdio(false)
using namespace std;

int main()
{
	int a;
	cin >> a;
	cin.tie(NULL);

	for (int i{ 1 }; i<=a; i++){
		int b, c;
		cin >> b >> c;
		cout << "Case #" << i << ": " << b + c << "\n";
	}
	return 0;
}