#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2){
	if(s1.length() == s2.length()){
		int it=0;
		while(it<s1.length() && ((s1[it]-'0')==(s2[it]-'0')))
			it++;
		if((s1[it]-'0') < (s2[it]-'0'))
			return true;
		else
			return false;
	}
	else{
		if(s1.length() < s2.length())
			return true;
		else
			return false;
	}
}

int main(){
	int N;
	cin>>N;
	
	vector<string>table;
	
	for(int i{0}; i<N; i++){
		string s;
		cin>>s;
		table.push_back(s);
	}
	
	sort(table.begin(), table.end(), compare);
	
	for(int i{0}; i<N; i++){
		if(i==0){
			cout<<table[i]<<endl;
		}
		else if(i!=0){
			if(table[i]==table[i-1]){}
			else
				cout<<table[i]<<endl;
		}
	}
	
	return 0;
}