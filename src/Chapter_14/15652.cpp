#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main(){
	
	cin.tie(NULL);
	cout.tie(NULL);
	
	int max, length;
	cin>>max>>length;
	
	vector<int>result;
	for(int i{0}; i<length; i++){
		result.push_back(1);
	}
	
	while(true){
		
		bool end=true;
		for(int i{0}; i<result.size(); i++){
			cout<<result[i]<<" ";
			
			// 배열의 모든 값이 max값이면 반복문 종료 => 하나라도 max값이 아니면 반복문 계속
			if(result[i]!=max)
				end=false;
		}
		cout<<"\n";
		
		if(end==true)
			break;
		
		값이 max 값인 모든 값을 원상복구
		if(result[result.size()-1]+1 > max){
			unsigned long int i=result.size()-1;
			
			while(result[i] + 1 > max)
				i--;
			
			result[i]++;
			
			for(unsigned long int j{i+1}; j<=result.size()-1; j++){
				result[j]=result[i];
			}
		}
		else
			result[result.size()-1]++;
	}
	return 0;
}



















