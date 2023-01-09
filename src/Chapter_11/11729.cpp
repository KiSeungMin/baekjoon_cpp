#include<iostream>
#include<cmath>
#include<string>
#define sync_with_stdio(false)
using namespace std;

string move1(string s){
	for(size_t i{0}; i<s.length(); i++){
		if(s[i]=='2'){
			s[i]='3';
			continue;
		}
		if(s[i]=='3'){
			s[i]='2';
			continue;
		}
	}
	return s;
}

string move2(string s){
	for(size_t i{0}; i<s.length(); i++){
		if(s[i]=='1'){
			s[i]='2';
			continue;
		}
		if(s[i]=='2'){
			s[i]='1';
			continue;
		}
	}
	return s;
}

string hanoii(int count){
	if(count==1){
		return "13";
	}
	else{
		return (move1(hanoii(count-1)) + "13" + move2(hanoii(count-1)));
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	
	cin>>K;
	
	cout<<static_cast<unsigned int>(pow(2, K)-1)<<endl;
	
	string answer=hanoii(K);
	
	for(size_t i{0}; i<answer.length(); i=i+2){
		cout<<answer[i]<<" "<<answer[i+1]<<"\n";
	}
	
	return 0;
}