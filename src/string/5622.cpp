#include<iostream>
#include<string>
using namespace std;

int dial(string& str);

int main(){

	string str;
	cin >> str;
	cout << dial(str);
	
	return 0;
}

int dial(string& str)
{
	int arr[15] = { 0 };
	int result{ 0 };

	for (int i{ 0 }; i < str.size(); i++){
		if (str[i] >= 65 && str[i] <= 67)
			arr[i] = 3;
		
		else if (str[i] >= 68 && str[i] <= 70)
			arr[i] = 4;
		
		else if (str[i] >= 71 && str[i] <= 73)
			arr[i] = 5;
		
		else if (str[i] >= 74 && str[i] <= 76)
			arr[i] = 6;
		
		else if (str[i] >= 77 && str[i] <= 79)
			arr[i] = 7;
		
		else if (str[i] >= 80 && str[i] <= 83)
			arr[i] = 8;
		
		else if (str[i] >= 84 && str[i] <= 86)
			arr[i] = 9;
		
		else if (str[i] >= 87 && str[i] <= 90)
			arr[i] = 10;
	}

	for (int i{ 0 }; i < 15; i++)
		result += arr[i];

	return result;
}