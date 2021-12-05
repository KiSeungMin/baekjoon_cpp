#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long M;
vector<long long>arr;

bool getResult(long long num);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i{0}; i < N; i++){
        long long num;
        cin>>num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    long long start = 0;
    long long end=arr[arr.size()-1];
    long long answer=0;

    while(true){

        long long mid =(start + end)/2; 

        if(getResult(mid)){

            if(getResult(mid+1) == false){
                answer=mid;
                break;
            }

            start = mid;
            continue;
        }

        else{

            if(getResult(mid - 1)){
                answer=mid-1;
                break;
            }

            end=mid;
            continue;
        }
    }

    cout<<answer<<"\n";

    return 0;
}

bool getResult(long long num){

    int start=0;
    int end = N-1;
    int mid=0;

    while(true){

        mid = (start + end) / 2;

        if(arr[mid] == num)
            break;

        else if(start >= end)
            break;

        else if(arr[mid] > num){
            end=mid-1;
            continue;
        }

        else{
            start=mid+1;
            continue;
        }
    }

    long long result=0;

    for(int i{mid-1}; i < N; i++){

        if(i < 0 || arr[i] < num)
            continue;
            
        result += arr[i]-num;
    }

    if(result >= M)
        return true;

    return false;
}