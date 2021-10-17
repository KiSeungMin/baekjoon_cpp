#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int count, max;
	cin>>count>>max;
	
	vector<int>num;
	for(int i{0}; i<count; i++){
		int n;
		cin>>n;
		num.push_back(n);
	}
	
	vector<int> iter={0,1,2};
	int answer=0;

	while(iter[0]!=count-3|| iter[1]!=count-2 || iter[2]!=count-
		  1)
	{
		int result=num[iter[0]]+num[iter[1]]+num[iter[2]];
		
		// 합이 찾는 값일 경우 -> 탐색 종료
		if(result==max){
			cout<<result<<endl;
			return 0;
		}
		
		// 현재 최대값 < 구한 값 < 찾는 값일 경우
		else if(result>answer && result<max){
			answer=result;
		}
		
		iter[iter.size()-1]++;
		
		for(int i{iter.size()-1}; i>=1; i--){
			if(iter[i]>(count-iter.size()+i)){
				iter[i-1]++;
				iter[i]=iter[i-1]+1;
			}
		}
		
		for(int i{0}; i<iter.size()-1; i++){
			if(iter[i]<=(count-iter.size()+i) && iter[i+1] > (count-
			iter.size()+i+1)){
				iter[i+1]=iter[i]+1;
			}
		}
	}
	
	iter[0]=count-3;
	iter[1]=count-2;
	iter[2]=count-1;
	
	int result=num[iter[0]]+num[iter[1]]+num[iter[2]];
	if((result == max) || (result>answer && result <max)){
		answer=result;
	}
		
	cout<<answer<<endl;
	return 0;
}