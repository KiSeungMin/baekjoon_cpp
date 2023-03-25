#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){

    int N; cin >> N;
    vector<pair<long long, long long>>arr;
    for(int i{0}; i < N; i++){
        long long num1 , num2;
        cin >> num1 >> num2;
        arr.push_back({num1, num2});
    }

    long long result = 0;
    for(int i{0}; i < N - 1; i++){
        result += (arr[i].first * arr[i + 1].second) - (arr[i + 1].first * arr[i].second);
    }
    result += (arr[N-1].first * arr[0].second - (arr[0].first * arr[N - 1].second));

    if(result < 0)
        result *= -1;

    long double answer = static_cast<long double> (result) / (2.0);

    cout<< setprecision(1)<<fixed<<answer<<endl;

    return 0;
}