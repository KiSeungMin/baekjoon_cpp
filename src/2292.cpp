#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	long unsigned int num;
	cin>>num;
	
	vector<long unsigned int>arr;
	
	arr.push_back(0);
	arr.push_back(1);
	
	int answer;
	int count=6;
	
	while(arr[arr.size()-1]<1000000000){
		arr.push_back(arr[arr.size()-1]+count);
		count+=6;
	}
	
	if(num>arr[arr.size()-1]){
		cout<<arr.size();
		return 0;
	}
	
	for(size_t i{0}; i<arr.size()-1; i++){
		if(num> arr[i] && num<=arr[i+1]){
			answer=i+1;
			break;
		}
	}
	
	cout<<answer<<endl;
	
	return 0;
}