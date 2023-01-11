#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int>arr;
	for (int i{ 0 }; i < N; i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	for (size_t i{ 0 }; i < arr.size(); i++){
		cout << arr[i] << endl;
	}
    
	return 0;
}