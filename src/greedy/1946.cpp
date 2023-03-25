#include<iostream>
#include<vector>
#include<algorithm>
#define sync_with_stdio(false)
using namespace std;

int getAnswer(){

    int N; cin >> N;
    vector<pair<int, int>> arr = {{0, 0}};

    int num1, num2;
    for(int i{0}; i < N; i++){
        cin >> num1 >> num2;
        
        arr.push_back({num1, num2});
    }

    sort(arr.begin(), arr.end());

    int answer = 0;

    int limit_now = N + 1;
    for(int i{1}; i <= N; i++){
        num1 = arr[i].first;
        num2 = arr[i].second;

        if(num2 < limit_now){
            answer++;
            limit_now = num2;
        }
    }

    return answer;
}

int main(){

    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for(int t{0}; t < T; t++){

        cout<<getAnswer()<<"\n";
    }

    return 0;
}