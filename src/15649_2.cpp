#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int maxNum, length;

void getAnswer(int number, int position, vector<int> result);

int main(){
	
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>maxNum>>length;
	
	vector<int>arr(length, 0);
	
	for(int i{0}; i<maxNum; i++){
		getAnswer(i,0,arr);
	}
	
	return 0;
}

void getAnswer(int number, int position, vector<int> result){
	
	for(int i{0}; i<position; i++){
		if(result[i]==number)
			return;
	}
	
	result[position]=number;
	
	if(position==length-1){
		for(size_t i{0}; i<result.size(); i++){
			cout<<result[i]+1<<" ";
		}
		cout<<"\n";
		return;
	}
	
	else{
		for(int i{0}; i<maxNum; i++){
			getAnswer(i, position+1, result);
		}
	}
}