#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int main(){
	
    cin.tie(NULL);

	int size;
	cin>>size;
	
	vector<int>input_arr;

	for(int i{0}; i<size; i++){
		int num;
		cin>>num;
		input_arr.push_back(num);
	}

    cout<<*min_element(input_arr.begin(), input_arr.end())<< " "<<*max_element(input_arr.begin(), input_arr.end())<<"\n";
	
	
	return 0;
}