#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	cin>>N;
	
	for(int i{1}; i<=N; i++){
		int tmp=i;
		
		string s=to_string(i);
		for(size_t j{0}; j<s.length(); j++){
			int num=s[j]-'0';
			tmp+=num;
		}
		
		if(tmp==N){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}