#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int N, M;
vector<int>input_arr;
vector<int>goal_arr;

void getInput(){

    cin >> N;

    for(int i{0};i < N; i++){
        int num; cin >> num;
        input_arr.push_back(num);
    }

    cin >> M;
    for(int i{0}; i < M; i++){
        int num; cin >> num;
        goal_arr.push_back(num);
    }
}

bool binarySearch(int start, int end, int goal){

    if(start > end)
        return false;

    int center = (start + end) / 2;
    int center_element = input_arr[center];

    if(center_element == goal)
        return true;

    if(center_element < goal)
        return binarySearch(center + 1, end, goal);

    else
        return binarySearch(start, center - 1, goal);
}

int main(){

    cin.tie(NULL); cout.tie(NULL);

    getInput();

    sort(input_arr.begin(), input_arr.end());

    for(auto element : goal_arr)
        cout<<(binarySearch(0, N - 1, element) ? 1 : 0)<<"\n";

    return 0;
}