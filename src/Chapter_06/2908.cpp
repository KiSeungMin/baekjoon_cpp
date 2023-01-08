#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	string str1, str2;
	
	cin>>str1>>str2;
	
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

    int str_to_num1 = stoi(str1);
    int str_to_num2 = stoi(str2);

    int result = str_to_num1 > str_to_num2 ? str_to_num1 : str_to_num2;
    cout<<result<<"\n";
	
	return 0;
}