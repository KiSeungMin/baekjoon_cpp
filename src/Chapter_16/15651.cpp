#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int getCntMax(int down, int up){
	int result=1;
	for(int i{0}; i<up; i++){
		result=result*down;
	}
	return result;
}

int main(){
	
	cout.tie(NULL);
	cin.tie(NULL);
	
	int max;
	int length;
	cin>>max>>length;
	
	vector<int>result;
	for(int i{0}; i<length; i++){
		result.push_back(1);
	}
	
	int cnt=0;
	int cntMax=getCntMax(max, length);

	while(cnt<cntMax-1){
		for(int i{0}; i<result.size(); i++){
			cout<<result[i]<<" ";
		}
		cout<<"\n";
		cnt++;
		
		if(result[result.size()-1]+1 > max){
			unsigned long int i=result.size()-1;
			while(result[i]+1 > max)
				i--;
			
			result[i]++;
			
			for(unsigned long int j=i+1; j<=result.size()-1; j++)
				result[j]=1;
		}
		else
			result[result.size()-1]++;
	}
		
	for(int i{0}; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
		cout<<"\n";	
	
	return 0;
}