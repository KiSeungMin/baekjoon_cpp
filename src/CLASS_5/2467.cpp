#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N; 
int index1, index2;
long long answer = 200000000000;

void getAnswer(vector<long long>&arr){

    int start_index = 0;
    int end_index = N - 1;

    while(start_index < end_index){
        long long result = arr[start_index] + arr[end_index];

        if(abs(result) < answer){
            answer = abs(result);
            index1 = start_index;
            index2 = end_index;
        }

        if(result > 0){
            end_index--;
        }
        else{
            start_index++;
        }
    }
}

int main(){

    cin >> N;
    vector<long long>arr(N , 0);
    for(int i{0}; i < N; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    getAnswer(arr);

    cout<<arr[index1]<<" "<<arr[index2]<<endl;

    return 0;
}