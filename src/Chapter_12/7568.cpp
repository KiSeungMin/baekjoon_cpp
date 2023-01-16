#include<iostream>
#include<array>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	array<array<int, 2>, 50>arr;
	vector<int>rank;
	for (int i{ 0 }; i < N; i++){
		int weight, height;
		cin >> weight >> height;
		arr[i][0] = weight;
		arr[i][1] = height;
	}

	for (size_t i{ 0 }; i < N; i++)
		rank.push_back(1);
	
	for (size_t i{ 0 }; i < rank.size()-1; i++){
		for (size_t j{ i+1 }; j < rank.size(); j++){
			if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1])
				rank[j] += 1;

			else if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				rank[i] += 1;
		}
	}

	for (size_t i{ 0 }; i < N; i++)
		cout << rank[i] << " ";
        
	return 0;
}