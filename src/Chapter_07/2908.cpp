#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	string num1, num2;
	
	cin>>num1>>num2;
	
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	
	for(size_t i{0};i<num1.length();i++){
		if(num1[i]==num2[i]){
			continue;
		}
		else{
			if(num1[i]>num2[i]){
				cout<<num1<<endl;
				break;
			}
			else{
				cout<<num2<<endl;
				break;
			}
		}
	}
	
	return 0;
}