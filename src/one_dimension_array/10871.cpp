#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

int main()
{
	cin.tie(NULL);
	
	int N, X;
	cin >> N >> X;
	vector<int>input_arr;
	for (int i{ 0 }; i < N; i++){
		int a;
		cin >> a;
		input_arr.push_back(a);
	}

    vector<int>result;
	for (size_t i{ 0 }; i < input_arr.size(); i++){
		if (X > input_arr[i])
			result.push_back(input_arr[i]);
		
	}

    for(auto result_element : result){
        cout<<result_element<<" ";
    }
	return 0;
}