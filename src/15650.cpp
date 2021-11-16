#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
	if(n==1 || n==0)
		return 1;
	else
		return n*factorial(n-1);
}

int main(){
	
	int max;
	int length;
	int cnt=0;
	int cntMax;
	vector<vector<int>>answer;
	
	cin>>max>>length;
	
	cntMax=(factorial(max))/((factorial(max-length))*(factorial(length)));
	
	vector<int>table;
	for(int i{0}; i<length; i++){
		table.push_back(i+1);
	}

	while(cnt<=cntMax){
		
		for(int i{0}; i<table.size(); i++){
			cout<<table[i]<<" ";
		}	
		cout<<endl;
		cnt++;
		if(cnt>=cntMax)
			break;
		
		if(table[table.size()-1]+1 > max){
			unsigned long int i=table.size()-1;
			while(true){
				if(i>=1 && (table[i-1]==table[i]-1))
					i=i-1;
				else
					break;
			}
			table[i-1]++;
			for(i; i<=table.size()-1; i++){
				table[i]=table[i-1]+1;
			}
		}
		else{
			table[table.size()-1]++;
		}
	}	
	
	
	return 0;
}