#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

bool compare(pair<int, int>&a, pair<int, int>& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin>>N;

    vector<pair<int, int>> input_arr(N);
    for(int i{0}; i < N; i++){
        cin>>input_arr[i].first>>input_arr[i].second;
    }

    sort(input_arr.begin(), input_arr.end(), compare);

	for (int i{ 0 }; i < N; i++){
		cout << input_arr[i].first << " " << input_arr[i].second << "\n";
	}
	return 0;
}