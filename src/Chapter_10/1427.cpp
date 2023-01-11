#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string str;
	str = to_string(N);
	sort(str.begin(), str.end());
	reverse(str.begin(), str.end());
	cout << str;
	return 0;
}