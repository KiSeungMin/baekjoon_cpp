#include<iostream>
#include<vector>
#define sync_with_stdio(false)
using namespace std;

const int LIMIT = 41;

int main(){

    cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int>>answer_arr(LIMIT, {0, 0});
    answer_arr[0] = {1, 0};
    answer_arr[1] = {0, 1};

    for(int i{2}; i < LIMIT; i++){
        answer_arr[i] = {(answer_arr[i - 2].first + answer_arr[i - 1].first), (answer_arr[i - 2].second + answer_arr[i - 1].second)};
    }

    int T; cin >> T;
    for(int t{0}; t < T; t++){
        int num; cin >> num;
        cout<<answer_arr[num].first<<" "<<answer_arr[num].second<<"\n";
    }    

    return 0;
}