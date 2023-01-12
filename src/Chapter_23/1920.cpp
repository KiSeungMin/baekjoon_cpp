#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(int n, int start, int end, vector<int>& arr);

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    vector<int>numArr;

    for(int i{0}; i < N; i++){
        int num;
        cin>>num;
        numArr.push_back(num);
    }

    sort(numArr.begin(), numArr.end());

    int M;
    cin>>M;

    vector<int>board;

    for(int i{0}; i < M; i++){
        int num;
        cin>>num;
        cout<<search(num, 0, N-1, numArr)<<"\n";
    }

    return 0;
}

int search(int n, int start, int end, vector<int>& arr){

    if(start > end)
        return 0;

    int center = (end + start)/2;

    if(arr[center] == n){
        return 1;
    }

    else if (arr[center] > n){
        return search(n, start, center - 1, arr);
    }

    else {
        return search(n, center + 1, end, arr);
    }
}