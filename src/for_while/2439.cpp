#include<iostream>
#define sync_with_stdio(false)
using namespace std;

int main()
{
	int a;
	cin >> a;
	cin.tie(NULL);
	for (int i{ 1 }; i <= a; i++){
		for (int j{ 0 }; j < a - i; j++)
			cout << " ";
	
		for (int j{ 0 }; j < i; j++)
			cout << "*";
		
		cout << "\n";
	}
	return 0;
}