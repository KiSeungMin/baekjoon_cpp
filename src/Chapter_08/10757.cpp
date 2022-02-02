#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	string a, b;
	
	cin>>a>>b;
	
	if(a.length()>b.length()){
		while(a.length()!=b.length()){
			b.insert(0, "0");
		}
	}
	
	else if(a.length() < b.length()){
		while(a.length()!=b.length()){
			a.insert(0, "0");
		}
	}
	
	int plus=0;
	vector<int>answer;
	
	for(int i{a.length()-1}; i>=0; i--){
		int aInt=a[i]-'0';
		int bInt=b[i]-'0';
		
		int sum=aInt+bInt+plus;
		
		plus=sum/10;
		answer.push_back(sum%10);
	}
	
	if(plus>0){
		answer.push_back(plus);
	}
	
	for(int i{answer.size()-1};  i>=0; i--){
		cout<<answer[i];
	}
	
	return 0;
}