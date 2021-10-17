#include<iostream>
#include<string>
using namespace std;

int main(){
	
	int N;
	cin>>N;
	
	int count=0;
	int num=666;
	
	while(count<N){
		string s=to_string(num);
		for(size_t i{0}; i<s.length()-2; i++){
			string tmp="";
			tmp=tmp+s[i]+s[i+1]+s[i+2];
			if(tmp=="666"){
				count++;
				break;
			}
		}
		num++;
	}
	
	cout<<num-1<<endl;
	
	return 0;
}