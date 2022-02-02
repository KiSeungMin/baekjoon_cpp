#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	
	vector<int>distanceCase;
	
	int testCase;
	cin>>testCase;
	
	for(int i{0};i<testCase;i++){
		int x,y;
		cin>>x>>y;
		
		int distance=y-x;
		distanceCase.push_back(distance);
	}
	
	vector<unsigned int> table;
	
	table.push_back(0);
	table.push_back(1);
	table.push_back(2);
	
	int count=2;
	unsigned long long int sum=0;
	
	while(sum<pow(2,31)){
		sum=0;
		
		for(int i{1}; i<count; i++){
			sum+=i;
		}	
		table.push_back(sum*2+count);
		table.push_back((sum+count)*2);
		
		sum=(sum+count)*2;
		
		count++;
	}
		
	for(int i{0}; i<distanceCase.size(); i++){
		
		for(size_t j{0}; j<table.size()-1; j++){
			if(distanceCase[i]>table[j] && distanceCase[i]<=table[j+1]){
				cout<<j+1<<endl;
				break;
			}
		}
		
		if(distanceCase[i]>table[table.size()-1]){
			cout<<table.size()<<endl;
		}
		
	}
	return 0;
}