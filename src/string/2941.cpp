#include<iostream>
#include<string>
#include<vector>
using namespace std;

int croa(string& str);

int main(){

	string str;
	cin >> str;
	cout << croa(str)<<"\n";
	
	return 0;
}

int croa(string& str){

	int sum{ 0 };
	str.push_back(' ');
	str.push_back(' ');
	string result_str = "";

	for (int i{ 0 }; i < str.size(); i++)
	{
		if (str[i] == 'c' && str[i + 1] == '=')
			result_str.push_back('c');
	
		else if (str[i] == 'c' && str[i + 1] == '-')
			result_str.push_back('b');
			
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
			result_str.push_back('m');
		
		else if (str[i] == 'd' && str[i + 1] == '-')
			result_str.push_back('d');
		
		else if (str[i] == 'l' && str[i + 1] == 'j')
			result_str.push_back('l');
		
		else if (str[i] == 'n' && str[i + 1] == 'j')
			result_str.push_back('n');
		
		else if (str[i] == 's' && str[i + 1] == '=')
			result_str.push_back('s');
		
		else if (str[i] == 'z' && str[i + 1] == '=')
			result_str.push_back('z');
			
		else {
			result_str.push_back(str[i]);
            i--;
		}

        i++;
	}

	for (int i{ 0 }; i < result_str.size(); i++){
		if (result_str[i] >= 97 && result_str[i] <= 122)
			sum++;
	}

	return sum;
}