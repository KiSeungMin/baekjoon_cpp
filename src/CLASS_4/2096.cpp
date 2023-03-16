#include<iostream>
#include<vector>
#define sync_with_stdio(false);
using namespace std;

int getMax(int a, int b){
    return a > b ? a : b;
}

int getMin(int a, int b){
    return a > b ? b : a;
}

int main(){

    int N; cin >> N;
    int num1, num2, num3;
    int min1, min2, min3;
    int max1, max2, max3;

    vector<int>min_dp = {0, 0, 0};
    vector<int>max_dp = {0, 0, 0}; 

    for(int i{0}; i < N; i++){
        cin >> num1 >> num2 >> num3;

        min1 = num1 + getMin(min_dp[0], min_dp[1]);
        min2 = num2 + getMin(getMin(min_dp[0], min_dp[1]), min_dp[2]);
        min3 = num3 + getMin(min_dp[1], min_dp[2]);

        max1 = num1 + getMax(max_dp[0], max_dp[1]);
        max2 = num2 + getMax(getMax(max_dp[0], max_dp[1]),  max_dp[2]);
        max3 = num3 + getMax(max_dp[1], max_dp[2]);

        min_dp = {min1, min2, min3};
        max_dp = {max1, max2, max3};
    }

    int min_answer = 2000000000;
    int max_answer = 0;

    for(int i{0}; i < 3; i++){
        min_answer = getMin(min_answer, min_dp[i]);
        max_answer = getMax(max_answer, max_dp[i]);
    }

    cout<<max_answer<<" "<<min_answer<<"\n";

    return 0;
}