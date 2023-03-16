#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int N;
    cin>>N;

    vector<pair<int, int>>arr;

    for(int i{0}; i < N; i++){

        int start;
        int end;
        cin>>start>>end;

        pair<int, int>tmp={end, start};
        arr.push_back(tmp);
    }

    // 끝나는 시간을 기준으로 오름차순 정렬
    sort(arr.begin(), arr.end());

    int timeNow=0;
    int answer=0;

    for(int i{0}; i < N; i++){

        if(arr[i].second >= timeNow){

            timeNow=arr[i].first;
            answer++;
        }
    }

    cout<<answer<<endl;

    return 0;
}