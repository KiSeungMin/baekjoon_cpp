#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;


int main(){
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<int>arr(N, 0);
	for (int i{ 0 }; i < N; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	for (size_t i{ 0 }; i < arr.size(); i++){
		cout << arr[i] << "\n";
	}
	return 0;
}