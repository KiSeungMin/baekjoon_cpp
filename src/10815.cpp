#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	int size;
	cin>>size;
	
	vector<int>arr;
	
	for(int i{0}; i<size; i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	
	sort(arr.begin(), arr.end());
	
	cout<<arr[0]<<" "<<arr[size-1]<<endl;
	
	return 0;
}